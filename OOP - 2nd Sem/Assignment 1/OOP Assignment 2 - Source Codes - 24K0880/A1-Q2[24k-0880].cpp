#include <iostream>
#include <tuple>
#include <cstdlib>
#include <ctime>

using namespace std;

class Robot{
public:
    string name;
    int hits;

    Robot(string n): name(n), hits(0) {}

    void hitBall(int &ballX, int &ballY, const string &direction){
        if (direction == "up") ballY--;
        else if (direction == "down") ballY++;
        else if (direction == "left") ballX--;
        else if (direction == "right") ballX++;

        hits++;
        cout << name << " hit the ball " << direction << " to (" << ballX << ", " << ballY << ")\n";
    }

    int getHits(){
        return hits;
    }
};

class Ball{
private:
    int x;
    int y;

public:
    Ball(int startX = 0, int startY = 0): x(startX), y(startY) {}

    int getX(){ return x; }
    int getY(){ return y; }

    void move(int dx, int dy){
        x += dx;
        y += dy;
    }

    tuple<int, int> getPosition(){
        return make_tuple(x, y);
    }
};

class Goal{
private:
    int x;
    int y;

public:
    Goal(int _x = 3, int _y = 3): x(_x), y(_y) {}

    bool isGoalReached(int ballX, int ballY){
        return (ballX == x && ballY == y);
    }
};

class Team{
public:
    string teamName;
    Robot *player;

    Team(string name, Robot *robotPlayer): teamName(name), player(robotPlayer) {}
};

class Game{
public:
    Team team1;
    Team team2;
    Ball ball;
    Goal goal;

    Game(Team t1, Team t2): team1(t1), team2(t2), ball(0, 0), goal() {}

    void startGame(){
        cout << "Starting the game!\n";
        play(&team1);
        play(&team2);
        declareWinner();
    }

    void play(Team *team){
	    cout << "\nTeam " << team->teamName << " is playing!\n";
	
	    while (!goal.isGoalReached(ball.getX(), ball.getY())){
	        string directions[] = {"up", "down", "left", "right"};
	        int randomIndex = rand() % 4;
	
	        int ballX = ball.getX();
	        int ballY = ball.getY();
	
	        team->player->hitBall(ballX, ballY, directions[randomIndex]);
	
	        ball.move(ballX - ball.getX(), ballY - ball.getY());
	    }
	
	    cout << team->teamName << " reached the goal in " << team->player->getHits() << " hits!\n";
	}

    void declareWinner(){
        cout << "\nGame Over!\n";
        int hitsTeam1 = team1.player->getHits();
        int hitsTeam2 = team2.player->getHits();

        if (hitsTeam1 < hitsTeam2)
            cout << "Winner: " << team1.teamName << endl;
        else if (hitsTeam2 < hitsTeam1)
            cout << "Winner: " << team2.teamName << endl;
        else
            cout << "It's a draw!\n";
    }
};

int main(){
    srand(time(0));

    Robot r1("Robo-One"), r2("Robo-Two");
    Team t1("Red Warriors", &r1), t2("Blue Strikers", &r2);
    Game footballGame(t1, t2);

    footballGame.startGame();

    return 0;
}

