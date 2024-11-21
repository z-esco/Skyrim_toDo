#include <string>
#include <fstream>
#include <forward_list>
#include <iostream>

char menu();
short select(char op);

int main(){
    //fills  gets every step index
    //fills double vector with plan vectors comprised of step vectors which eill essentially act as a datbase
    std::string planName;
    std::string step;
    short ind;
    short ctr = 0;

    std::ifstream read1Line;
    
    while(std::cin >> planName){
        read1Line.open(planName);

        std::vector<std::string> temp;

        if(read1Line.is_open()){
            read1Line >> ind; 
            indOfPlans.push_back(ind); 
            while(read1Line >> step)
                {temp.push_back(step);}
            allPlans.push_back(temp);
            allPlans[ctr] = temp;
             ctr++;

        planName = "";
        step = "";
        }

        read1Line.close();
    }                             



    //runs main menu function
    char response;
    while(response != 'Q'){

        //get current to-do list
        //print current to-do list
        for(int i = 0; i < indOfPlans.size(); i++){
            currentPlans[i] = allPlans[i][indOfPlans[i]];
            std::cout << "> ("<< i+1 << ") " << currentPlans[i] <<std::endl;
        }
        
        response = menu();
        short sel = response;

        switch(response){
            case 'X' :
                //cross out and advance task
                std::cout << "\n\n\tCompleted: " << allPlans[sel][indOfPlans[sel]] <<std::endl << std::endl;
                indOfPlans[sel]++;
                break;
            case 'P'  :
                for(int i = 0; i < allPlans[sel].size(); i++){
                    std::cout << std::endl << allPlans[sel][i] << std::endl;
                }
                break;

            default: 
                std::cout << "Invalid Input. Try again\n";
                break;
        }


    }


    return 0;
}
    
    char menu(){
        char response;

        std::cout << "(X) Cross off task\n(P) Display Plan\n(Q)uit\n";
        std::cin >> response;

        std::toupper(response);

        return response;
    }

    short select(char op){
        short sel;
        std::cout << "Select a task to ";
        switch(op){
            case 'X': std::cout << "cross out: ";
            break;
            case 'P': std::cout << "reaveal its complete plan: ";
            break;
        default: break;
        }

        std::cin >> sel;
        sel--;

        return sel;
    }


class Entry{
    private:
        std::string task;
        bool completed;

    public:
        Entry();
        Entry::Entry(std::string t);

};

class Quest{
    private:
        std::string name;
        std::forward_list<Entry> taskList;
        Quest* subquest;

    public:
        Quest();
       void addEntry(Entry& e);

};

Entry::Entry(){
    completed = false;
    std::cin >> task;
}

Entry::Entry(std::string t){
    task = t;
    completed = false;
}

Quest::Quest(){
    std::cin >> name;
    subquest = nullptr;
}

void Quest::addEntry(Entry& e){
    taskList.push_back(e)
}