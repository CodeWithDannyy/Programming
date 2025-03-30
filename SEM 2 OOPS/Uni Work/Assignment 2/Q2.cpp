#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Ghost
{
    protected:
        string name;
        string workerName;
        int scareLevel;

    public:
        Ghost(string name, string workerName) : name(name) , workerName(workerName)
        {
            scareLevel = (rand() % 10) + 1;
        }

        virtual void haunt()
        {
            cout << name << " (played by " << workerName << ") is haunting!!!!!!" << endl; 
        }

        friend ostream& operator<<(ostream& os, const Ghost& g)
        {
            os << "Ghost : " << g.name << " | Played By : " << g.workerName << " | Scare Level : " << g.scareLevel << endl;
            return os;
        }

        Ghost operator+(const Ghost& object)
        {
            Ghost tempGhost(name + " & " + object.name, workerName + " & " + object.workerName);
            tempGhost.scareLevel = this->scareLevel + object.scareLevel;
            return tempGhost;
        }

        int getScareLevel() const { return scareLevel; }
        virtual ~Ghost() {}
};

class Poltergeist : virtual public Ghost 
{
    public:
        Poltergeist(string name, string worker) : Ghost(name, worker) {}
    
        void haunt()
        {
            cout << name << " moves objects around the room!" << endl;
        }
    };
    
class Banshee : public Ghost 
{
    public:
        Banshee(string name, string worker) : Ghost(name, worker) {}
    
        void haunt()
        {
            cout << name << " lets out a bloodcurdling scream!" << endl;
        }
};
    
class ShadowGhost : virtual public Ghost 
{
    public:
        ShadowGhost(string name, string worker) : Ghost(name, worker) {}
    
        void haunt()
        {
            cout << name << " whispers creepily from the darkness..." << endl;
        }
};

class ShadowPoltergeist : public ShadowGhost, public Poltergeist
{
    public:
        ShadowPoltergeist(string name, string worker) : Ghost(name,worker), ShadowGhost(name, worker) , Poltergeist(name, worker) {}

        void haunt()
        {
            ShadowGhost::haunt();
            Poltergeist::haunt();
        }
};

class Visitor
{
    private:
        string Name;
        int bravery;
    
    public:
        Visitor(string Name, int bravery) : Name(Name), bravery(bravery) {}

        void react(int scareLevel) 
        {
            if (scareLevel < bravery - 2)
                cout << Name << " laughs at the ghost!" << endl;
            else if (scareLevel > bravery + 2)
                cout << Name << " screams and runs away!" << endl;
            else
                cout << Name << " has a shaky voice..." << endl;
        }

        int getBravery() const { return bravery; }
        string getName() const { return Name;}
};

class HauntedHouse 
{
    Ghost* ghosts[3];
    
    public:
        HauntedHouse(Ghost* g1, Ghost* g2, Ghost* g3)
        {
            ghosts[0] = g1;
            ghosts[1] = g2;
            ghosts[2] = g3;
        }
    
        friend void visit(Visitor vistors[], int visitorCount, HauntedHouse& Hhouse);
};

void visit(Visitor vistors[], int visitorCount, HauntedHouse& Hhouse)
{
    for(int i = 0; i < visitorCount; i++)
    {
        cout << vistors[i].getName() << " entering the haunted house...." << endl;
        for(int j = 0; j < 3; j++)
        {
            Hhouse.ghosts[j]->haunt();
            vistors[i].react(Hhouse.ghosts[i]->getScareLevel());
            cout << endl;
        }
    }
}


int main()
{
    srand(time(0));

    Banshee bs("Screaming Lady", "Sarah");
    Poltergeist plg("Flying Chair", "John");
    ShadowPoltergeist splg("Shadow Mover", "Mike");

    Visitor v1("Alice", 3);
    Visitor v2("Bob", 6);
    Visitor v3("Charlie", 9);

    Visitor visitors[] = {v1,v2,v3};

    HauntedHouse h1(&bs, &plg, &splg);

    visit(visitors,3,h1);
    return 0;
}