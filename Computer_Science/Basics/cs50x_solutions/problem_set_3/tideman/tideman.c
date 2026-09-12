#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

// utils
bool isCyclic(bool locked[MAX][MAX]);
bool dfs(bool locked[MAX][MAX], int v, bool visited[], bool stack[]);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }

        }

        record_preferences(ranks);
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
/*
    - look for a candidate called "name"
    - if candidate found, update "ranks" and return "true". ranks[i] is the voters "i"th preference
    - if no candidate found, don't update any ranks and return "false"
*/
bool vote(int rank, string name, int ranks[])
{
    for (int k = 0; k < candidate_count; k++) {
        if (strcmp(candidates[k], name) == 0) {
            ranks[rank] = k;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
/*
    - call once for each voter
    - update the "preferences" array based on the current voter's ranks
*/
void record_preferences(int ranks[])
{
    int left_pointer, right_pointer;
    left_pointer = 0;

    for (; left_pointer < candidate_count -1; left_pointer++) {
        right_pointer = left_pointer + 1;
        for (; right_pointer < candidate_count; right_pointer++) {
            preferences[ranks[left_pointer]][ranks[right_pointer]] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
/*
    - add each pair of candidates to "pairs" array if one candidate is preferred over the other
    - Update global variable "pair_count" to be the total number of pairs
*/
void add_pairs(void)
{
    int max_pairs = (MAX * (MAX - 1) / 2);
    pair temp[max_pairs];
    for (int i = 0; i < candidate_count; i++) {
        for (int j = 0; j < candidate_count; j++) {

            // same candidate
            if (i == j) {
                continue;
            }

            // handle ties
            if (preferences[i][j] == preferences[j][i]) {
                continue;
            }


            // handle duplicates
            bool duplicate = false;
            for (int k = 0; k < pair_count; k++) {
                if ((pairs[k].winner == i && pairs[k].loser == j) ||
                    (pairs[k].winner == j && pairs[k].loser == i)) {
                        duplicate = true;
                    }
            }
            if (duplicate) {
                continue;
            }

            // populate pairs
            if (pair_count < max_pairs) {
                if (preferences[i][j] > preferences[j][i]) {
                    pair duel;
                    duel.winner = i;
                    duel.loser = j;
                    pairs[pair_count] = duel;
                } else {
                    pair duel;
                    duel.winner = j;
                    duel.loser = i;
                    pairs[pair_count] = duel;
                    }
                    pair_count++;
                }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int m = 1;
    for (int i = pair_count - 1; i >= 0; i--) {
        int min_idx = pair_count - m;

        // find actuall minimum
        for (int j = i - 1; j >= 0; j--) {
            // changing this!
            if ((preferences[pairs[j].winner][pairs[j].loser]) - (preferences[pairs[j].loser][pairs[j].winner]) <
                (preferences[pairs[min_idx].winner][pairs[min_idx].loser]) - (preferences[pairs[min_idx].loser][pairs[min_idx].winner])) {
                min_idx = j;
            }
        }

        // move minimum to its position
        pair temp = pairs[min_idx];
        pairs[min_idx] = pairs[i];
        pairs[i] = temp;
        m++;
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
// starting with strongest pair, "lock in" each pair to candidate graph
// as long as no cycles
/*
    - Update "locked" to create the locked graph by adding all edges in
      decreasing order of victory strength, as long as there is no cycle

    - use "pairs" struct array to populare bool locked[MAX][MAX];
*/
void lock_pairs(void)
{
    int win_p;
    int los_p;

    for (int i = 0; i < pair_count; i++) {
        win_p = pairs[i].winner;
        los_p = pairs[i].loser;

        // add edge
        locked[pairs[i].winner][pairs[i].loser] = true;

        // check cycle
        bool isCyclic(bool locked[candidate_count][candidate_count]);

        if (isCyclic(locked)) {
            locked[pairs[i].winner][pairs[i].loser] = false;
            continue;
        }
    }
    return;
}

// Print the winner of the election
// source of the graph (no arrow to them)
/*
    - you may assume there will not be ore than one source!
*/
void print_winner(void)
{
    bool source[candidate_count];
    int i, j;
    for (i = 0; i < candidate_count; i++) {
        source[i] = false;
    }

    for (i = 0; i < candidate_count; i++) {

        for (j = 0; j < candidate_count; j++) {
            if (locked[i][j] == true && source[j] == false) {
                source[j] = true;
            }
        }
    }

    for (i = 0; i < candidate_count; i++) {
        if (source[i] == false) {
            printf("%s\n", candidates[i]);
            return;
        }
    }
    return;
}

/*
    - UTILS
*/
bool isCyclic(bool l[MAX][MAX]) {
    bool visited[candidate_count];
    bool stack[candidate_count];

    for (int i = 0; i < candidate_count; i++) {
        visited[i] = false;
        stack[i] = false;
    }

    for (int i = 0; i < candidate_count; i++) {
        if (!visited[i]) {

            if (dfs(l, i, visited, stack)) {
                return true;
            }
        }
    }
    return false;
}


bool dfs(bool l[MAX][MAX], int v, bool visited[], bool stack[]) {
    visited[v] = true;
    stack[v] = true;

    for (int i = 0; i < candidate_count; i++) {
        if (l[v][i] == true) {
            if (!visited[i]) {
                if (dfs(l, i, visited, stack)) {
                    return true;
                }
            } else if (stack[i]) {
                return true;
            }
        }
    }

    stack[v] = false;
    return false;
}

