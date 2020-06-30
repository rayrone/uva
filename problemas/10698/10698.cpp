/* 10698 - Football Sort */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <unordered_map>

using namespace std;

#define NAME_SIZE 16
#define WIN_POINTS 3
#define DRAW_POINTS 1

struct team
{
    char name[NAME_SIZE];
    int position = 0;
    int points = 0;
    int games = 0;
    int goals_scored = 0;
    int goals_suffered = 0;
    int goals_difference = 0;
    float pcte_earned_points = 0;
};

int compare(const void *a, const void *b)
{
    team *ta = (team *)a;
    team *tb = (team *)b;

    if (ta->points != tb->points)
        return tb->points - ta->points;

    if (ta->goals_difference != tb->goals_difference)
        return tb->goals_difference - ta->goals_difference;

    return tb->goals_scored - ta->goals_scored;
}

int comparePosition(const void *a, const void *b)
{
    int cmp = compare(a, b);

    if (cmp != 0)
        return cmp;

    team *ta = (team *)a;
    team *tb = (team *)b;

    return strcasecmp(ta->name, tb->name);
}

void playGame(team *t, int goals_scored, int goals_suffered)
{
    t->games++;
    t->goals_scored += goals_scored;
    t->goals_suffered += goals_suffered;
    t->goals_difference = t->goals_scored - t->goals_suffered;

    if (goals_scored == goals_suffered)
        t->points += DRAW_POINTS;
    else if (goals_scored > goals_suffered)
        t->points += WIN_POINTS;
}

int main()
{
    int n_teams, n_games;
    bool firstInput = true;

    while (scanf("%d %d", &n_teams, &n_games) != EOF)
    {
        if (n_teams == 0 && n_games == 0)
            break;

        firstInput ? firstInput = false : putchar('\n');

        unordered_map<string, int> teams_map;
        team teams_v[n_teams];

        for (int i = 0; i < n_teams; i++)
        {
            scanf("%s", teams_v[i].name);
            string team_name(teams_v[i].name);

            if (teams_map.count(teams_v[i].name) == 0)
                teams_map[team_name] = i;
        }

        char home_team[NAME_SIZE], away_team[NAME_SIZE];
        int goals_home_team, goals_away_team;

        for (int i = 1; i <= n_games; i++)
        {
            scanf("%s %d - %d %s", home_team, &goals_home_team, &goals_away_team, away_team);

            string str_home_team(home_team);
            string str_away_team(away_team);

            team *th = &teams_v[teams_map[str_home_team]];
            team *ta = &teams_v[teams_map[str_away_team]];

            playGame(th, goals_home_team, goals_away_team);
            playGame(ta, goals_away_team, goals_home_team);
        }

        qsort(teams_v, n_teams, sizeof(team), comparePosition);

        for (int i = 0; i < n_teams; i++)
        {
            team *t = &teams_v[i];
            t->position = i + 1;

            char str_pos[4];

            if (i > 0 && compare(&teams_v[i - 1], t) == 0)
                sprintf(str_pos, "%3s", "");
            else
                sprintf(str_pos, "%2d.", t->position);

            char str_pcte[8];

            if (t->games > 0)
            {
                t->pcte_earned_points = 100 * ((float)t->points) / (t->games * WIN_POINTS);
                sprintf(str_pcte, "%6.2f", t->pcte_earned_points);
            }
            else
                sprintf(str_pcte, "%6s", "N/A");

            printf("%s %15s %3d %3d %3d %3d %3d %s\n", str_pos, t->name, t->points, t->games, t->goals_scored,
                   t->goals_suffered, t->goals_difference, str_pcte);
        }
    }

    return 0;
}
