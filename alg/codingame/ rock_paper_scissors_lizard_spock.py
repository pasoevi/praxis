import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

class Player:
    def __init__(self, num, sign, opponents = []):
        self.num = num
        self.sign = sign
        self.opponents = opponents

    def add_oponent(self, opponent):
        if not self.opponents:
            self.opponents = [opponent]
        else:
            self.opponents.append(opponent)


class Result:
    win = 1
    lose = -1
    tie = 0


def who_wins(player1, player2):
    rules = {
        'C': {
            'R': Result.lose,
            'P': Result.win,
            'S': Result.lose,
            'L': Result.win,
            'C': Result.tie,
        },
        'R': {
            'C': Result.win,
            'P': Result.lose,
            'S': Result.lose,
            'L': Result.win,
            'R': Result.tie,
        },
        'P': {
            'C': Result.lose,
            'P': Result.tie,
            'S': Result.win,
            'L': Result.lose,
            'R': Result.win,
        },
        'S': {
            'C': Result.win,
            'P': Result.lose,
            'S': Result.tie,
            'L': Result.lose,
            'R': Result.win,
        },
        'L': {
            'C': Result.lose,
            'P': Result.win,
            'S': Result.win,
            'L': Result.tie,
            'R': Result.lose,
        },
    }

    player1_result = rules[player1.sign][player2.sign]
    if player1_result == Result.win:
        return player1
    elif player1_result == Result.lose:
        return player2
    else:
        return player1 if player1.num < player2.num else player2


n = int(input())
players = []
for i in range(n):
    numplayer, signplayer = input().split()
    numplayer = int(numplayer)

    players.append(Player(numplayer, signplayer))

# Write an action using print
# To debug: print("Debug messages...", file=sys.stderr)

def tournament(players):
    if len(players) == 1:
        return players[0]

    new_players = []
    for i in range(len(players)):
        if i % 2 == 1:
            player1 = players[i-1]
            player2 = players[i]
            if who_wins(player1, player2).num == player1.num:
                player1.add_oponent(player2)
                new_players.append(player1)
            else:
                player2.add_oponent(player1)
                new_players.append(player2)
    return tournament(new_players)

winner = tournament(players)
print(winner.num)
print(" ".join(map(lambda x: str(x.num), winner.opponents)))