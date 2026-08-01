#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 30
#define POINTS_PER_WIN 2
#define POINTS_PER_DRAW 1

struct Team {
    char name[MAX_NAME_LEN];
    int played, won, lost, draw;
    int points;
};

// Reads a non-negative integer, re-prompting until valid.
// Rejects empty input, non-numeric input, decimals, and negative numbers.
int read_nonneg_int(const char *prompt) {
    char buf[64];
    long val;

    while (1) {
        printf("%s", prompt);
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            continue;
        }

        // strip trailing newline
        buf[strcspn(buf, "\n")] = '\0';

        char *endptr;
        val = strtol(buf, &endptr, 10);

        // reject: empty input, trailing junk (e.g. "3.5", "abc"), or negative
        if (endptr == buf || *endptr != '\0' || val < 0) {
            printf("Invalid input. Please enter a non-negative whole number.\n");
            continue;
        }
        break;
    }
    return (int)val;
}

// Reads a team name safely (bounded width) and flushes the rest of the line.
void read_team_name(char *dest, int size, const char *prompt) {
    printf("%s", prompt);
    scanf("%29s", dest); // width limited to MAX_NAME_LEN - 1
    while (getchar() != '\n'); // flush leftover characters on the line
    (void)size;
}

void input_team(struct Team *t, int index) {
    char prompt[80];

    snprintf(prompt, sizeof(prompt), "Enter the name of team %d: ", index + 1);
    read_team_name(t->name, MAX_NAME_LEN, prompt);

    snprintf(prompt, sizeof(prompt), "Enter the number of matches played by %s: ", t->name);
    t->played = read_nonneg_int(prompt);

    // Won: cannot exceed total played
    while (1) {
        snprintf(prompt, sizeof(prompt), "Enter the number of matches won by %s: ", t->name);
        t->won = read_nonneg_int(prompt);
        if (t->won > t->played) {
            printf("Matches won cannot exceed matches played (%d).\n", t->played);
            continue;
        }
        break;
    }

    // Lost: won + lost cannot exceed total played
    while (1) {
        snprintf(prompt, sizeof(prompt), "Enter the number of matches lost by %s: ", t->name);
        t->lost = read_nonneg_int(prompt);
        if (t->won + t->lost > t->played) {
            printf("Won + lost (%d) cannot exceed matches played (%d).\n",
                   t->won + t->lost, t->played);
            continue;
        }
        break;
    }

    // Draw: must exactly account for the remaining matches
    int remaining = t->played - t->won - t->lost;
    while (1) {
        snprintf(prompt, sizeof(prompt), "Enter the number of matches drawn by %s: ", t->name);
        t->draw = read_nonneg_int(prompt);
        if (t->draw != remaining) {
            printf("Matches drawn must equal played - won - lost = %d.\n", remaining);
            continue;
        }
        break;
    }

    t->points = (t->won * POINTS_PER_WIN) + (t->draw * POINTS_PER_DRAW);
}

int compare_points(const void *a, const void *b) {
    const struct Team *ta = a;
    const struct Team *tb = b;
    return tb->points - ta->points; // descending order
}

void print_table(struct Team teams[], int n) {
    printf("\nCRICKET TOURNAMENT SCORECARD\n");
    printf("----------------------------------------------------------\n");
    printf("| %-20s %-8s %-5s %-5s %-5s %-7s|\n",
           "Team Name", "Played", "Won", "Lost", "Draw", "Points");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("| %-20s %-8d %-5d %-5d %-5d %-7d|\n",
               teams[i].name,
               teams[i].played,
               teams[i].won,
               teams[i].lost,
               teams[i].draw,
               teams[i].points);
    }
    printf("----------------------------------------------------------\n");
}

int main(void) {
    int n = read_nonneg_int("Enter the number of teams: ");
    if (n == 0) {
        printf("No teams entered. Exiting.\n");
        return 1;
    }

    struct Team teams[n];
    for (int i = 0; i < n; i++) {
        input_team(&teams[i], i);
    }

    qsort(teams, n, sizeof(struct Team), compare_points);
    print_table(teams, n);

    return 0;
}