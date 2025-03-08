#include<iostream>
using namespace std;

class Skill
{
    private:
        int skillID;
        string skillName;
        string description;
    public:
        Skill() : skillID(0) , skillName("") , description("") {}
        Skill(int skillID, string skillName, string description) : skillID(skillID) , skillName(skillName) , description(description) {}

        void showSkillDetails()
        {
            cout << "Skill ID : " << skillID << endl;
            cout << "Skill Name : " << skillName << endl;
            cout << "Description : " << description << endl;
        }

        void updateSkillDescription(string newSkillDescription)
        {
            description = newSkillDescription;
        }

        int getSkillID() {return skillID ; }
        string getSkillName() { return skillName;}
};

class Sport
{
    private:
        int sportID;
        string sportName;
        string sportDescription;
        Skill requiredSkill[10];
        int skillCount;
    public:
        Sport() : sportID(0) , sportName("") , sportDescription(""){}
        Sport(int sportID, string name, string description)
        {
            this->sportID = sportID;
            this->sportName = name;
            this->sportDescription = description;
            skillCount = 0;
        }

        void addSkill(Skill s)
        {
            if(skillCount < 10)
            {
                requiredSkill[skillCount++] = s;
            }
            else
                cout << "Cannot Add more skills" << endl;
        }

        void removeSkill(Skill s)
        {
            for(int i = 0; i < skillCount; i++)
            {
                if(requiredSkill[i].getSkillID() == s.getSkillID())
                {
                    for (int j = i; j < skillCount-1; j++)
                    {
                        requiredSkill[j] = requiredSkill[j+1];
                    }
                    skillCount--;
                    cout << "Skill Removed, Skill ID : " << s.getSkillID() << endl;
                    return;
                }
            }
            cout << "Skill ID Not Found " << endl;
        }
        
};

class Student;

class Mentor{

    private:
        int mentorID;
        string mentorName;
        Sport* sportsExpertise[5];
        int maxLearners;
        Student* assignedLearners[5];
        int learnerCount;
    public:
        Mentor() : mentorID(0) , mentorName(""), maxLearners(0) 
        {
            for (int i = 0; i < 5; i++)
            {
                sportsExpertise[i] = nullptr;
                assignedLearners[i] = nullptr;
            }
            learnerCount = 0;
        }
        Mentor(int mentorID, string mentorName, int maxLearners) : mentorID(mentorID), mentorName(mentorName), maxLearners(maxLearners) 
        {
            for (int i = 0; i < 5; i++)
            {
                sportsExpertise[i] = nullptr;
                assignedLearners[i] = nullptr;
            }
            learnerCount = 0;
        }

        void assignLearner(Student* s);

        void removeLearner(Student *s);

        void viewLearners();

        void provideGuidance()
        {
            cout << "Providing guidance to learners..." << endl;
        }

        int getMentorID() { return mentorID ;}
        string getMentorName() { return mentorName;}

};

class Student
{
    private:
        int studentID;
        string studentName;
        int age;
        Sport sportsInterests[5];
        int sportsCount;
        Mentor *mentorAssigned;
    public:
        Student() : studentID(0) , studentName(""), age(0) , sportsCount(0), mentorAssigned(nullptr) {}
        Student(int studentID, string studentName, int age) : studentID(studentID) , studentName(studentName), age(age), sportsCount(0), mentorAssigned(nullptr) {}
        

        void registerForMentorship(Mentor *m)
        {
            mentorAssigned = m;
            cout << "Mentor Assigned, Name : " << m->getMentorName() << endl;

            m->assignLearner(this);
        }

        void viewMentorDetails()
        {
            if(mentorAssigned)
                cout << "Mentor ID : " << mentorAssigned->getMentorID() << ", Name : " << mentorAssigned->getMentorName() << endl;
            else
                cout << "No mentor Assigned" << endl;
        }

        void updateSportsInterest(Sport s)
        {
            if(sportsCount < 5)
                sportsInterests[sportsCount++] = s;
            else
                cout << "Cannot add more sports" << endl;
        }

        int getStudentId() { return studentID ; }
        string getStudentName() { return studentName; }
        int getStudentAge() { return age;}

};

void Mentor::assignLearner(Student* s)
{
    if(learnerCount < maxLearners)
    {
        assignedLearners[learnerCount++] = s;
        cout << "Student Assigned, ID: " << s->getStudentId() << endl;
    }
    else
        cout << "Cannot assing more learner" << endl;
}

void Mentor::removeLearner(Student *s)
{
    for(int i = 0; i < learnerCount; i++)
    {
        if(assignedLearners[i]->getStudentId() == s->getStudentId())
        {
            for(int j = i; j < learnerCount -1 ; j++)
            {
                assignedLearners[j] = assignedLearners[j+1];
            }
            learnerCount--;
            cout << "Student Removed, ID : " << s->getStudentId() << endl;
            return;
        }
    }
        cout << "Student ID not found" << endl;
}

void Mentor::viewLearners()
        {
            if(learnerCount == 0)
            {
                cout << "No Learners Assigned" << endl;
                return;
            }
            for(int i = 0; i < learnerCount; i++)
            {
                cout << "Student " << i+1 << endl;
                cout << "ID : " << assignedLearners[i]->getStudentId() << endl;
                cout << "Name : " << assignedLearners[i]->getStudentName() << endl;
                cout << "Age : " << assignedLearners[i]->getStudentAge() << endl;
            }
        }

int main()
{
    Mentor m1(101,"Ali",5);
    Student s1(101,"Saad",25);
    cout << "Mentor Details " << endl;
    cout << "Mentor ID : " << m1.getMentorID() << endl;
    cout << "Mentor Name : " << m1.getMentorName() << endl;
    cout << "Student Details  " << endl;
    cout << "Student ID : " << s1.getStudentId() << endl;
    cout << "Student Name : " << s1.getStudentName() << endl;
    cout << "Student Age : " << s1.getStudentAge() << endl;
    cout << endl;
    cout << s1.getStudentName() << " registering for mentorship" <<endl; 
    s1.registerForMentorship(&m1);

    Sport sport1(1,"Football","World's Most Played Sport");
    s1.updateSportsInterest(sport1);
    cout << s1.getStudentName() << " has chosen " << "Football as his sport." << endl;

    cout << endl;

    cout << "-----Viewing " << m1.getMentorName() << "'s learners list-----" << endl;
    m1.viewLearners();
    cout << endl;
    Skill skill1(1, "Dribbling", "The ability to move the ball with control");
    skill1.showSkillDetails();

    sport1.addSkill(skill1);

    m1.provideGuidance();

    m1.removeLearner(&s1);
    m1.viewLearners();

    return 0;
}