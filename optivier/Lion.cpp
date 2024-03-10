#include <string>
#include <list>
#include <bits/stdc++.h>


using namespace std;

struct LionDescription
{
    string name;
    int height;
};

struct LionSchedule
{
    string name;
    int enterTime;
    int exitTime;
};

class LionCompetition
{
    map<pair<int, int>, string> myLionEnter, myLionExit;//{{time, height}, name}
    map<string, int> myLionHeight;

    map<int, int> curLions;//{height, freq}
    map<int, set<string>> myCurLions;//{height, {names}}
public:
    LionCompetition(list<LionDescription> lions, list<LionSchedule> schedule)
    {
        /* Enter your code here. */
        for(auto it = lions.begin(); it != lions.end(); it++)
            myLionHeight[it -> name] = it -> height;
        
        for(auto it = schedule.begin(); it != schedule.end(); it++){
            myLionEnter[{it -> enterTime, myLionHeight[it -> name]}] = it -> name;
            myLionExit[{it -> exitTime, myLionHeight[it -> name]}] = it -> name;
        }
    }

    void lionEntered(int currentTime, int height)
    {
        /* Enter your code here. */
        if(myLionEnter.find({currentTime, height}) != myLionEnter.end()){
            string name = myLionEnter[{currentTime, height}];
            myCurLions[height].insert(name);
        }
        else{
            curLions[height]++;
        }
    }

    void lionLeft(int currentTime, int height)
    {
        /* Enter your code here. */

        if(myLionExit.find({currentTime, height}) != myLionExit.end()){
            string name = myLionExit[{currentTime, height}];
            myCurLions[height].erase(myCurLions[height].find(name));
            if(myCurLions[height].size() == 0){
                myCurLions.erase(height);
            }
        }else{
            if(--curLions[height] == 0) 
                curLions.erase(height);
        }
    }

    list<string> getBiggestLions()
    {
        /* Enter your code here. */
        list<string> res;
        set<string> s;
        if(!myCurLions.size() || !curLions.size()) 
            return res;
        
        int maxH = curLions.rbegin() -> first;
        auto it = myCurLions.lower_bound(maxH);
        for(;it != myCurLions.end(); it++){
            set<string> cur = it -> second;
            for(auto lionName: cur)
                s.insert(lionName);
        }
        for(auto name: s)
            res.push_back(name);
        return res;
    }
};

int main()
{
	// string operation;

	// list<LionDescription> descriptions;
	// list<LionSchedule> schedule;

	// do
	// {
	// 	cin >> operation;

	// 	if (operation == "definition")
	// 	{
	// 		string name;
	// 		int size;
	// 		cin >> name >> size;

	// 		descriptions.push_back({name, size});
	// 	}
	// 	if (operation == "schedule")
	// 	{
	// 		string name;
	// 		int enterTime;
	// 		int exitTime;
	// 		cin >> name >> enterTime >> exitTime;

	// 		schedule.push_back({name, enterTime, exitTime});
	// 	}
	// } while (operation != "start");

	// LionCompetition lionCompetition(descriptions, schedule);

	// do
	// {
	// 	int currentTime;
	// 	cin >> currentTime >> operation;

	// 	if (operation == "enter")
	// 	{
	// 		int size;
	// 		cin >> size;

	// 		lionCompetition.lionEntered(currentTime, size);
	// 	}
	// 	if (operation == "exit")
	// 	{
	// 		int size;
	// 		cin >> size;

	// 		lionCompetition.lionLeft(currentTime, size);
	// 	}
	// 	if (operation == "inspect")
	// 	{
	// 		list<string> lions = lionCompetition.getBiggestLions();

	// 		cout << lions.size();

	// 		for (const string &name : lions)
	// 		{
	// 			cout << " " << name;
	// 		}

	// 		cout << "\n";
	// 	}
	// }
	// while (operation != "end");

	return 0;
}