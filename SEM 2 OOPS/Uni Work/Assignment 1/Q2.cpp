#include<iostream>
using namespace std;

class Ball
{
    private:
        int x,y;
    public:
        Ball() : x(0) , y(0) {}
        void move(int dx, int dy)
        {
            x += dx;
            y += dy;
        }

        int getX() { return x; }
        int getY() { return y; }

        pair<int, int> getPosition()
        {
            return {x,y};
        }
}; 

class Robot
{
    private:
        string robotName;
        int hits;
    public:
        Robot() : robotName("Unknown") , hits(0) {}
        Robot(string robotName) : robotName(robotName) , hits(0) {}

        void hitBall(int &ballX, int &ballY, const string &direction)
        {
            if(direction == "up") 
                ballY++;
            else if(direction == "down")
                ballY--;
            else if (direction == "right")
                ballX++;
            else if(direction == "left")
                ballX--;
            else
                cout << "Invalid Direction " << endl;

            hits++;
            cout << robotName << " hit the ball " << direction << ", Position ("<<ballX<<","<<ballY<<")" << endl;
        }   

        int getHits() { return hits; }
        string getName() {return robotName; }
 
};

class Goal
{
    private:
        const int goalX = 3, goalY = 3;
    public:
        int isGoalReached(int ballX, int ballY)
        {
            return ballX >= goalX && ballY >= goalY;
        }
};

class Team
{
    private:
        string teamName;
        Robot *robot;
    public:
        Team(string teamName, Robot *robot) : teamName(teamName), robot(robot) {}

        string getTeamName() { return teamName; }
        Robot* getRobot() { return robot;}
};

class Game
{
    private:
        Team *team1;
        Team *team2;
        Ball ball;
        Goal goal;
    public:
        Game(Team *team1, Team *team2) : team1(team1), team2(team2){}

        void play(Team *team)
        {
            ball = Ball();
            cout << "Team " << team->getTeamName() << " is playing"<<endl;
            cout << "Starting Position ("<<ball.getX()<<","<<ball.getY()<<")" << endl;
            Robot *robot = team->getRobot();
            string d;

            while(!goal.isGoalReached(ball.getX(),ball.getY()))
            {
                cout << "Enter Direction (right,left,up,down) : " ;
                getline(cin,d);
                
                int x = ball.getX();
                int y = ball.getY();
                robot->hitBall(x,y,d);
                ball.move(x-ball.getX(),y-ball.getY());
            }

            cout << "Goal Reached, Hits : " << robot->getHits() << endl;
        }

        void declareWinner()
        {
            int hits1 = team1->getRobot()->getHits();
            int hits2 = team2->getRobot()->getHits();

            cout << "Team " << team1->getTeamName() <<" hits : " << hits1 << endl;
            cout << "Team " << team2->getTeamName() <<" hits : " << hits2 << endl;

            if(hits1 < hits2)
                cout << "Team " << team1->getTeamName() << " is the Winner!" << endl;
            else if(hits1 > hits2)
                cout << "Team " << team2->getTeamName() << " is the Winner!" << endl;
            else
                cout << "Its a tie" << endl;
         }
        
        void startGame()
        {
            cout << "Starting Game..." << endl;
            play(team1);
            getchar();
            play(team2);
            declareWinner();
        }
};

int main()
{
    Robot r1("Messi"), r2("Ronaldo");
    Team t1("Barcelona",&r1), t2("Real Madrid",&r2);
    Game game(&t1,&t2);

    game.startGame();
    return 0;
}

