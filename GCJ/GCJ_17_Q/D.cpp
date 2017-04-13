
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <stack>
#include <cmath>
#include <string.h>
#include <queue>
#include <set>
#include <assert.h>
using namespace std;
 
typedef vector < string > vs;
typedef vector <int> vi;
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define deb(x) cout << #x << ": " << x << endl;
#define debv(x) for(int i = 0; i < (x).size(); i++) cout << x[i] << ' '; cout << endl;

const int MAX_GRID_SIZE = 105;
const int MAX_NODES = 405;
int GRID_SIZE;
int ld_conv[MAX_NODES][MAX_NODES];
int rd_conv[MAX_NODES][MAX_NODES];

int row_conv[MAX_NODES][MAX_NODES];
int col_conv[MAX_NODES][MAX_NODES];

int start_grid[MAX_GRID_SIZE][MAX_GRID_SIZE];
int end_grid[MAX_GRID_SIZE][MAX_GRID_SIZE];


int SRC = MAX_NODES - 2, SNK = MAX_NODES - 1;
int diag_graph[MAX_NODES][MAX_NODES];
int grid_graph[MAX_NODES][MAX_NODES];

inline int get_left_diag(int R, int C)
{
    // (N-1,0) --> 0, (0,N-1) -->  2*N-2
    return (C+(GRID_SIZE-1)-R);
}

inline int get_right_diag(int R, int C)
{
    // (0,0) --> 0, (N-1,N-1) --> 2*N-2
    return (R+C);
}

int bad_row[MAX_NODES], bad_col[MAX_NODES];
int bad_LD[MAX_NODES], bad_RD[MAX_NODES];

void prep(int N)
{
    GRID_SIZE = N;
    memset(diag_graph,0,sizeof(diag_graph));
    memset(grid_graph,0,sizeof(grid_graph));

    memset(bad_row,0,sizeof(bad_row));
    memset(bad_col,0,sizeof(bad_col));
    memset(bad_LD,0,sizeof(bad_LD));
    memset(bad_RD,0,sizeof(bad_RD));
    for(int rdx = 0; rdx < N; rdx++)
    {
        for(int cdx = 0; cdx < N; cdx++)
        {
            int LD = get_left_diag(rdx,cdx);
            int RD = get_right_diag(rdx,cdx);

            ld_conv[rdx][cdx] = LD;
            rd_conv[rdx][cdx] = RD;

            row_conv[LD][RD] = rdx;
            col_conv[LD][RD] = cdx;

            /* Setup diag graph */
            diag_graph[LD][RD] = 1;
            //diag_graph[SRC][LD] = 1;
            //diag_graph[RD][SNK] = 1;

            /* Setup grid graph */
            grid_graph[rdx][cdx] = 1;
            //grid_graph[SRC][rdx] = 1;
            //grid_graph[cdx][SNK] = 1;
        }
    }
    memset(start_grid,0,sizeof(start_grid));
    memset(end_grid,0,sizeof(end_grid));
}

int match[MAX_NODES];
int done[MAX_NODES];

int (*G)[MAX_NODES][MAX_NODES];
int (*bad_left)[MAX_NODES];
int (*bad_right)[MAX_NODES];
int augment(int vert)
{
    if(vert == -1) return 1;
    if((*bad_left)[vert]) return 0;
    if(done[vert]) return 0;
    done[vert] = 1;
    for(int i = 0; i < MAX_NODES; i++)
    {
        if((*bad_right)[i]) continue;
        if((*G)[vert][i])
        {
           if(augment(match[i]))
           {
               match[i] = vert;
               return 1;
           }
        }
    }
    return 0;
}

int bipmat()
{
    int ret = 0;
    memset(done,0,sizeof(done));
    memset(match,-1,sizeof(match));
    for(int i = 0; i < MAX_NODES; i++)
    {
       if(augment(i))
       {
           ret++;
       }
       memset(done,0,sizeof(done));
    }
    return ret;
}

bool check_graph()
{
    int total_grid[MAX_GRID_SIZE][MAX_GRID_SIZE];

    int hit_row[MAX_NODES], hit_col[MAX_NODES];
    int hit_LD[MAX_NODES], hit_RD[MAX_NODES];

    memset(hit_row,0,sizeof(hit_row));
    memset(hit_col,0,sizeof(hit_col));
    memset(hit_LD,0,sizeof(hit_LD));
    memset(hit_RD,0,sizeof(hit_RD));
    //deb(GRID_SIZE);

    bool ret = true;
    for(int rdx = 0; rdx < GRID_SIZE; rdx++)
    {
        for(int cdx = 0; cdx < GRID_SIZE; cdx++)
        {
            total_grid[rdx][cdx] = end_grid[rdx][cdx] + start_grid[rdx][cdx];
            int tt = total_grid[rdx][cdx];

            if(tt == 1 || tt == 3)
            {
                if(hit_row[rdx])
                {
                    printf("ROW HIT %d\n", rdx);
                    ret = false;
                }
                    
                hit_row[rdx] = 1;
                if(hit_col[cdx])
                {
                    printf("COL HIT %d\n", cdx);
                    ret = false;
                }
                hit_col[cdx] = 1;
            }
            if(tt == 2 || tt == 3)
            {
                int ld = ld_conv[rdx][cdx];
                int rd = rd_conv[rdx][cdx];
                if(hit_LD[ld])
                {
                    printf("LD HIT %d\n", ld);
                    ret = false;
                }
                hit_LD[ld] = 1;
                if(hit_RD[rd])
                {
                    
                    printf("RD HIT %d\n", rd);
                    ret = false;
                }
                hit_RD[rd] = 1;
            }
        }
    }
    return ret;
}

int main()
{
    int TT;
	cin >> TT;

	for(int test_case = 1; test_case <= TT; test_case++)
	{
        int N, M;
        cin >> N >> M;
        prep(N);
        int placed[M][3];
        for(int i = 0; i < M; i++)
        {
            char type = ' ';
            placed[i][2] = -1;
            cin >> type >> placed[i][0] >> placed[i][1];
            placed[i][0]--;
            placed[i][1]--;

            if(type == 'o') placed[i][2] = 3;
            if(type == '+') placed[i][2] = 2;
            if(type == 'x') placed[i][2] = 1;

            assert(placed[i][2] != -1);
        }

        int org_score = 0;
        for(int i = 0; i < M; i++)
        {
            int mr = placed[i][0], mc = placed[i][1], mt = placed[i][2];
            start_grid[mr][mc] = mt;

            int mld = ld_conv[mr][mc], mrd = rd_conv[mr][mc];

            if(mt == 3) org_score += 2;
            else org_score++;

            if(mt == 2 || mt == 3)
            {
                bad_LD[mld] = 1;
                bad_RD[mrd] = 1;
                //diag_graph[mld][mrd] = 0;
            }
            if(mt == 1 || mt == 3)
            {
                bad_row[mr] = 1;
                bad_col[mc] = 1;
                //grid_graph[mr][mc] = 0;
            }
        }

        G = &diag_graph;
        bad_left = &bad_LD;
        bad_right = &bad_RD;
        int diag_add = bipmat();
        for(int RN = 0; RN < MAX_NODES; RN++)
        {
            if(match[RN] == -1) continue;
            int LN = match[RN];

            int match_row = row_conv[LN][RN],
                match_col = col_conv[LN][RN];

            end_grid[match_row][match_col] += 2;
        }

        G = &grid_graph;
        bad_left = &bad_row;
        bad_right = &bad_col;
        int grid_add = bipmat();
        for(int RN = 0; RN < MAX_NODES; RN++)
        {
            if(match[RN] == -1) continue;
            int LN = match[RN];

            end_grid[LN][RN] += 1;
        }

        int total_added = 0;
        int added[MAX_NODES][2];
        char type_added[MAX_NODES];

        for(int rdx = 0; rdx < N; rdx++)
        {
            for(int cdx = 0; cdx < N; cdx++)
            {
                if(end_grid[rdx][cdx] > 0)
                {
                    added[total_added][0] = rdx + 1;
                    added[total_added][1] = cdx + 1;

                    int score = end_grid[rdx][cdx]+start_grid[rdx][cdx];
                    if(score == 3) type_added[total_added] = 'o';
                    else if(score == 2) type_added[total_added] = '+';
                    else type_added[total_added] = 'x';

                    total_added++;
                }
            }
        }
        if(check_graph() == false)
        {
            deb("NOOO");
            assert(false);
        }
        int total_score = org_score + diag_add + grid_add;
        printf("Case #%d: %d %d\n", test_case, total_score, total_added);
        for(int idx = 0; idx < total_added; idx++)
        {
            printf("%c %d %d\n",type_added[idx], added[idx][0], added[idx][1]);
        }
	}
	return 0;
}