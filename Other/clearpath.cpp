#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

typedef struct Waypoint {
	double x, y, penalty, wait;
} Waypoint;

inline double calc_dist(Waypoint a, Waypoint b) {
	return sqrt( pow(a.x-b.x, 2) + pow(a.y-b.y, 2) );
}
int main(int argc, char* argv[]) {

	const double WAYPOINT_LOAD_TIME = 10.0, END_X = 100.0, END_Y = 100.0;
	const double INF = 1e18;
	while(true) {

		int N;
		cin >> N;
		if(N == 0) break;

		Waypoint waypoints[N + 2];
		waypoints[0].x = waypoints[0].y = 0;
		waypoints[0].penalty = 0;
		waypoints[0].wait = 0;

		waypoints[N+1].x = END_X;
		waypoints[N+1].y = END_Y;
		waypoints[N+1].penalty = 0;
		waypoints[N+1].wait = WAYPOINT_LOAD_TIME;

		for(int idx = 1; idx <= N; idx++) {
			cin >> waypoints[idx].x >> waypoints[idx].y >> waypoints[idx].penalty;
			waypoints[idx].wait = WAYPOINT_LOAD_TIME;
		}

		double best_score[N+2];
		best_score[0] = 0.0;
		for(int idx = 1; idx < N+2; idx++) {
			double sum_skip = 0.0;
			best_score[idx] = INF;
			for(int prev_idx = idx-1; prev_idx >= 0; prev_idx--) {

				best_score[idx] = min(best_score[idx], sum_skip + (calc_dist(waypoints[idx], waypoints[prev_idx])/2.0) + best_score[prev_idx]);
				sum_skip += waypoints[prev_idx].penalty;
			}
			best_score[idx] += waypoints[idx].wait;
		}
		printf("%.3lf\n", best_score[N+1]);
	}

	return 0;
}