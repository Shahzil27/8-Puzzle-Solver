//
// Name: Shahzil Siddiqui
// SID: 200448986
// Assignment: 4
//

#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

const int rowSize = 32000;

class Node                           // class to define a node in the tree
{
public:

    string parentArr[rowSize][2];
    vector<string> listofStates;
    vector<string> pathtoFinal;
    stack<string> stack1;
    queue<string> queue1;
    string goal = "123804765";
    //int totalNodes = 0;                // will keep track of all nodes generated until we reach the goal state

public:
    Node()                                // defaut constructor
    {
        for (int i=0; i < rowSize; i++)
        {
            for (int j=0; j<2; j++)
            {
                parentArr[i][j] = "0";
            }
        }
    }

    int findAvailable()                 // finds the next available spot in the parents table 
    {
        for (int i=0; i < rowSize; i++)
        {
            for (int j=0; j<2; j++)
            {
                if (parentArr[i][j] == "0")
                {
                  return i;
                }
            }
        }

        return -1; 
    }

    void insertParentArr(string parent, string child)                // inserts the parent child combo in the table at the next available spot 
    {
        int i = findAvailable();

        if (i != -1)
        {
            for (int j=0; j<2; j++)
            {
                if (parentArr[i][j] == "0")
                {
                    if (j==0)   // for inserting parent
                    {
                        parentArr[i][j] = parent;
                    }
                    else if (j==1)
                    {
                        parentArr[i][j] = child;
                    }
                }
            }
        }

    }

    void printParentArr()                    // prints the array containing all the parents and childrens 
    {
        for (int i=0; i < rowSize; i++)
        {
            cout << "ROW " << i << ": ";
            for (int j=0; j<2; j++)
            {
                cout << parentArr[i][j] << " ";

            }
            cout << endl;
        }
    }


    bool notInList(string ch)              //checks if the new node has already been generated before 
    {
        //bool condition = true;

        for (int i=0; i < listofStates.size(); i++)
        {
            if (listofStates[i] == ch)
            {
                //condition = false;
                return false;
            }
        }
        return true;
    }


    void printboard(string s)                   // prints the strings in the tile format 
    {
        cout << " +---+---+---+" << endl;
        for (int i = 0; i < 9; i++)
        {
            if (s[i] == '0')
            {
                cout << " |  ";
            }
            else 
            {
                cout << " | " << s[i];
            }

            if (i == 2 || i == 5 || i == 8)
            {
                cout << " |" << endl;
                cout << " +---+---+---+" << endl;
            }
        }
        
    }


    void analyzeChild(string ch, string s, string mthd)           // checks that the new node has not been generated before and updates the parents child table then adds to queue/stack
    {
        if(notInList(ch))
        {
            insertParentArr(s, ch);     // updating the parent

            listofStates.push_back(ch);

            if (mthd == "depthfirst")
            {
                stack1.push(ch);
            }
            else if (mthd == "breadthfirst")
            {
                queue1.push(ch);
            }
        }
    }


    void developChildren(string s, string mthd)          // developing all possible children
    {
        //string zero = "0";
        if (s[0] == '0')
        {
            string ch1 = s;
            swap(ch1[0], ch1[3]);

            string ch2 = s;
            swap(ch2[0], ch2[1]);

            analyzeChild(ch2,s, mthd);
            analyzeChild(ch1,s, mthd);

        }
        else if (s[1] == '0')
        {
            string ch1 = s;
            swap(ch1[1], ch1[0]);

            string ch2 = s;
            swap(ch2[1], ch2[2]);

            string ch3 = s;
            swap(ch3[1], ch3[4]);

            analyzeChild(ch3,s, mthd);
            analyzeChild(ch2,s, mthd);
            analyzeChild(ch1,s, mthd);
        }
        else if (s[2] == '0')
        {
            string ch1 = s;
            swap(ch1[2], ch1[1]);

            string ch2 = s;
            swap(ch2[2], ch2[5]);

            analyzeChild(ch2,s, mthd);
            analyzeChild(ch1,s, mthd);
        }
        else if (s[3] == '0')
        {
            string ch1 = s;
            swap(ch1[3], ch1[0]);

            string ch2 = s;
            swap(ch2[3], ch2[4]);

            string ch3 = s;
            swap(ch3[3], ch3[6]);

            analyzeChild(ch3,s, mthd);
            analyzeChild(ch2,s, mthd);
            analyzeChild(ch1,s, mthd);
        }
        else if (s[4] == '0')
        {
            string ch1 = s;
            swap(ch1[4], ch1[3]);

            string ch2 = s;
            swap(ch2[4], ch2[1]);

            string ch3 = s;
            swap(ch3[4], ch3[5]);

            string ch4 = s;
            swap(ch4[4], ch4[7]);

            analyzeChild(ch4,s, mthd);
            analyzeChild(ch3,s, mthd);
            analyzeChild(ch2,s, mthd);
            analyzeChild(ch1,s, mthd);
        }
        else if (s[5] == '0')
        {
            string ch1 = s;
            swap(ch1[5], ch1[4]);

            string ch2 = s;
            swap(ch2[5], ch2[2]);

            string ch3 = s;
            swap(ch3[5], ch3[8]);

            analyzeChild(ch3,s, mthd);
            analyzeChild(ch2,s, mthd);
            analyzeChild(ch1,s, mthd);
        }
        else if (s[6] == '0')
        {
            string ch1 = s;
            swap(ch1[6], ch1[3]);

            string ch2 = s;
            swap(ch2[6], ch2[7]);

            analyzeChild(ch2,s, mthd);
            analyzeChild(ch1,s, mthd);
        }
        else if (s[7] == '0')
        {
            string ch1 = s;
            swap(ch1[7], ch1[6]);

            string ch2 = s;
            swap(ch2[7], ch2[4]);

            string ch3 = s;
            swap(ch3[7], ch3[8]);

            analyzeChild(ch3,s, mthd);
            analyzeChild(ch2,s, mthd);
            analyzeChild(ch1,s, mthd);
        }
        else if (s[8] == '0')
        {
            string ch1 = s;
            swap(ch1[8], ch1[7]);

            string ch2 = s;
            swap(ch2[8], ch2[5]);

            analyzeChild(ch2,s, mthd);
            analyzeChild(ch1,s, mthd);
        }
    }


    void developChildren2(string s, string mthd)          // developing all possible children for breadth first method
    {
        //string zero = "0";
        if (s[0] == '0')
        {
            string ch1 = s;
            swap(ch1[0], ch1[3]);

            string ch2 = s;
            swap(ch2[0], ch2[1]);

            analyzeChild(ch1,s, mthd);
            analyzeChild(ch2,s, mthd);

        }
        else if (s[1] == '0')
        {
            string ch1 = s;
            swap(ch1[1], ch1[0]);

            string ch2 = s;
            swap(ch2[1], ch2[2]);

            string ch3 = s;
            swap(ch3[1], ch3[4]);

            analyzeChild(ch1,s, mthd);
            analyzeChild(ch2,s, mthd);
            analyzeChild(ch3,s, mthd);
        }
        else if (s[2] == '0')
        {
            string ch1 = s;
            swap(ch1[2], ch1[1]);

            string ch2 = s;
            swap(ch2[2], ch2[5]);

            analyzeChild(ch1,s, mthd);
            analyzeChild(ch2,s, mthd);
        }
        else if (s[3] == '0')
        {
            string ch1 = s;
            swap(ch1[3], ch1[0]);

            string ch2 = s;
            swap(ch2[3], ch2[4]);

            string ch3 = s;
            swap(ch3[3], ch3[6]);

            analyzeChild(ch1,s, mthd);
            analyzeChild(ch2,s, mthd);
            analyzeChild(ch3,s, mthd);
        }
        else if (s[4] == '0')
        {
            string ch1 = s;
            swap(ch1[4], ch1[3]);

            string ch2 = s;
            swap(ch2[4], ch2[1]);

            string ch3 = s;
            swap(ch3[4], ch3[5]);

            string ch4 = s;
            swap(ch4[4], ch4[7]);

            analyzeChild(ch1,s, mthd);
            analyzeChild(ch2,s, mthd);
            analyzeChild(ch3,s, mthd);
            analyzeChild(ch4,s, mthd);
        }
        else if (s[5] == '0')
        {
            string ch1 = s;
            swap(ch1[5], ch1[4]);

            string ch2 = s;
            swap(ch2[5], ch2[2]);

            string ch3 = s;
            swap(ch3[5], ch3[8]);

            analyzeChild(ch1,s, mthd);
            analyzeChild(ch2,s, mthd);
            analyzeChild(ch3,s, mthd);
        }
        else if (s[6] == '0')
        {
            string ch1 = s;
            swap(ch1[6], ch1[3]);

            string ch2 = s;
            swap(ch2[6], ch2[7]);

            analyzeChild(ch1,s, mthd);
            analyzeChild(ch2,s, mthd);
        }
        else if (s[7] == '0')
        {
            string ch1 = s;
            swap(ch1[7], ch1[6]);

            string ch2 = s;
            swap(ch2[7], ch2[4]);

            string ch3 = s;
            swap(ch3[7], ch3[8]);

            analyzeChild(ch1,s, mthd);
            analyzeChild(ch2,s, mthd);
            analyzeChild(ch3,s, mthd);
        }
        else if (s[8] == '0')
        {
            string ch1 = s;
            swap(ch1[8], ch1[7]);

            string ch2 = s;
            swap(ch2[8], ch2[5]);

            analyzeChild(ch1,s, mthd);
            analyzeChild(ch2,s, mthd);
        }
    }


    void pathtoGoal(string target)             // shows the path move by move to reach the goal state 
    {

        if(target != "NULL")
        {
            for (int i=rowSize; i>-1; i--)
            {
                for (int j=1; j>=0; j--)
                {
                    if ((j==1)&&(parentArr[i][j] == target))
                    {
                        //cout << "test goal" << endl;
                        pathtoFinal.push_back(parentArr[i][j-1]); //record parent to vector
                        pathtoGoal(parentArr[i][j-1]);
                    }
                }
            }
        }


    }

    void depthFirstSearch(string s1)    // uses stack and depth first search method to reach goal state 
    {
        stack1.push(s1);
        insertParentArr("NULL", s1);
        listofStates.push_back(s1);
        int depth = 0;

        string foundAns = "";

        while ((stack1.empty() == false) && (listofStates.size() < 362881)) //&& (depth < 25))       // making sure stack is not empty and controling search through max depth
        {
            string s = stack1.top();
            stack1.pop();

            if (s == goal)
            {
                foundAns = s;
                break;
            }
            else
            {
                developChildren(s, "depthfirst");

                cout <<" Generated states: " << listofStates.size() << " / 362880" << endl;    // dynamically shows the numeber of states being generated before goal is reached 
            }

        }

        if (foundAns == goal && listofStates.size() < 32000)
        {

            pathtoFinal.push_back(foundAns);

            pathtoGoal(foundAns);

            cout << endl;
            cout << "Path to goal state:" << endl << endl;

            for(int i=(pathtoFinal.size())-2; i>-1; i--)
            {
                if (i==0)
                {
                    printboard(pathtoFinal[i]);
                }
                else
                {
                    printboard(pathtoFinal[i]); 

                    cout << "       | " << endl; 
                    cout << "       V " << endl;
                }
            }

        }
        else
        {
            cout << "Insufficient array memory: Too many (over 35,000) generated states to hold in array and print path." << endl;
        }


        cout << endl;
        cout << "The minimum number of moves required: " << pathtoFinal.size() - 2 << endl;
        cout << "The total number of generated nodes are: " << listofStates.size() << endl << endl;

    }



    void breadthFirstSearch(string s1)    // uses queue and beath search method to reach goal state
    {
        queue1.push(s1);
        insertParentArr("NULL", s1);
        listofStates.push_back(s1);
        int depth = 0;

        string foundAns = "";

        while ((queue1.empty() == false) && (listofStates.size() < 362881))       // making sure stack is not empty and controling search through max depth
        {
            string s = queue1.front();
            queue1.pop();

            if (s == goal)
            {
                foundAns = s;
                break;
            }
            else
            {
                developChildren2(s, "breadthfirst");
            }
        }

        if (foundAns == goal && listofStates.size() < 32000)
        {

            pathtoFinal.push_back(foundAns);

            pathtoGoal(foundAns);

            cout << endl;
            cout << "Path to goal state:" << endl << endl;

            for(int i=(pathtoFinal.size())-2; i>-1; i--)
            {
                if (i==0)
                {
                    printboard(pathtoFinal[i]);
                }
                else
                {
                    printboard(pathtoFinal[i]); 

                    cout << "       | " << endl; 
                    cout << "       V " << endl;
                }
            }

        }
        else
        {
            cout << "Insufficient array memory: Too many (over 35,000) generated states to hold in array and print path." << endl;
        }


        cout << endl;
        cout << "The minimum number of moves required: " << pathtoFinal.size() - 2 << endl;
        cout << "The total number of generated nodes are: " << listofStates.size() << endl << endl;

    }





    int findValue(int depth, string s)           // used by the best first method where value is assined by the total number of wrong placed tiles
    {
        int wrongPos = 0;
        if (s[0] != '1')
        {
            wrongPos = wrongPos + 1;
        }

        if (s[1] != '2')
        {
            wrongPos = wrongPos + 1;
        }

        if (s[2] != '3')
        {
            wrongPos = wrongPos + 1;
        }

        if (s[3] != '8')
        {
            wrongPos = wrongPos + 1;
        }

        if (s[4] != '0')
        {
            wrongPos = wrongPos + 1;
        }

        if (s[5] != '4')
        {
            wrongPos = wrongPos + 1;
        }

        if (s[6] != '7')
        {
            wrongPos = wrongPos + 1;
        }

        if (s[7] != '6')
        {
            wrongPos = wrongPos + 1;
        }

        if (s[8] != '5')
        {
            wrongPos = wrongPos + 1;
        }


        return wrongPos;

    }


    int findDistance(int depth, string s)              // used by the best first method where value is assigned by the number of moves to reach each num in its goal position
    {
        int m0, m1, m2, m3, m4, m5, m6, m7, m8;

        if (s[0] == '1')
            m1 = 0;
        else if (s[1] == '1')
            m1 = 1;
        else if (s[2] == '1')
            m1 = 2;
        else if (s[3] == '1')
            m1 = 1;
        else if (s[4] == '1')
            m1 = 2;
        else if (s[5] == '1')
            m1 = 3;
        else if (s[6] == '1')
            m1 = 2;
        else if (s[7] == '1')
            m1 = 3;
        else if (s[8] == '1')
            m1 = 4;

        if (s[0] == '2')
            m2 = 1;
        else if (s[1] == '2')
            m2 = 0;
        else if (s[2] == '2')
            m2 = 1;
        else if (s[3] == '2')
            m2 = 2;
        else if (s[4] == '2')
            m2 = 1;
        else if (s[5] == '2')
            m2 = 2;
        else if (s[6] == '2')
            m2 = 3;
        else if (s[7] == '2')
            m2 = 2;
        else if (s[8] == '2')
            m2 = 3;

        if (s[0] == '3')
            m3 = 2;
        else if (s[1] == '3')
            m3 = 1;
        else if (s[2] == '3')
            m3 = 0;
        else if (s[3] == '3')
            m3 = 3;
        else if (s[4] == '3')
            m3 = 2;
        else if (s[5] == '3')
            m3 = 1;
        else if (s[6] == '3')
            m3 = 4;
        else if (s[7] == '3')
            m3 = 3;
        else if (s[8] == '3')
            m3 = 2;

        if (s[0] == '8')
            m8 = 1;
        else if (s[1] == '8')
            m8 = 2;
        else if (s[2] == '8')
            m8 = 3;
        else if (s[3] == '8')
            m8 = 0;
        else if (s[4] == '8')
            m8 = 1;
        else if (s[5] == '8')
            m8 = 2;
        else if (s[6] == '8')
            m8 = 1;
        else if (s[7] == '8')
            m8 = 2;
        else if (s[8] == '8')
            m8 = 3;

        if (s[0] == '0')
            m0 = 2;
        else if (s[1] == '0')
            m0 = 1;
        else if (s[2] == '0')
            m0 = 2;
        else if (s[3] == '0')
            m0 = 1;
        else if (s[4] == '0')
            m0 = 0;
        else if (s[5] == '0')
            m0 = 1;
        else if (s[6] == '0')
            m0 = 2;
        else if (s[7] == '0')
            m0 = 1;
        else if (s[8] == '0')
            m0 = 2;

        if (s[0] == '4')
            m4 = 3;
        else if (s[1] == '4')
            m4 = 2;
        else if (s[2] == '4')
            m4 = 1;
        else if (s[3] == '4')
            m4 = 2;
        else if (s[4] == '4')
            m4 = 1;
        else if (s[5] == '4')
            m4 = 0;
        else if (s[6] == '4')
            m4 = 3;
        else if (s[7] == '4')
            m4 = 2;
        else if (s[8] == '4')
            m4 = 1;

        if (s[0] == '7')
            m7 = 2;
        else if (s[1] == '7')
            m7 = 3;
        else if (s[2] == '7')
            m7 = 4;
        else if (s[3] == '7')
            m7 = 1;
        else if (s[4] == '7')
            m7 = 2;
        else if (s[5] == '7')
            m7 = 3;
        else if (s[6] == '7')
            m7 = 0;
        else if (s[7] == '7')
            m7 = 1;
        else if (s[8] == '7')
            m7 = 2;

        if (s[0] == '6')
            m6 = 3;
        else if (s[1] == '6')
            m6 = 2;
        else if (s[2] == '6')
            m6 = 3;
        else if (s[3] == '6')
            m6 = 2;
        else if (s[4] == '6')
            m6 = 1;
        else if (s[5] == '6')
            m6 = 2;
        else if (s[6] == '6')
            m6 = 1;
        else if (s[7] == '6')
            m6 = 0;
        else if (s[8] == '6')
            m6 = 1;

        if (s[0] == '5')
            m5 = 4;
        else if (s[1] == '5')
            m5 = 3;
        else if (s[2] == '5')
            m5 = 2;
        else if (s[3] == '5')
            m5 = 3;
        else if (s[4] == '5')
            m5 = 2;
        else if (s[5] == '5')
            m5 = 1;
        else if (s[6] == '5')
            m5 = 2;
        else if (s[7] == '5')
            m5 = 1;
        else if (s[8] == '5')
            m5 = 0;


        int totaldist = m0 + m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8;
        return totaldist;
    }

    
    bool properSuccessor(string s, int i)       // will check if a num is followed by its proper successor clock wise, used by the H herustic 
    {
        if (s[i] + 1 == s[i+1])
        {
            return true;
        }
        
        return false;
    } 
    
    
    int findValueH(string s, int depth)      // used by the best first method and the defined H herusistic in assignment
    {
        int seq = 0; 

        for (int i = 0; i < 9; i++)
        {
            if (s[i] == '0' && s[4] != '0')
            {
                seq = seq + 2; 
            }
            else if(s[i] == s[4] && s[4] != '0')
            {
                seq = seq + 1; 
            }
            else if (s[4] != s[i] && properSuccessor(s, i) == true)
            {
                seq = seq + 0; 
            }
            else if (s[4] != s[i] && properSuccessor(s, i) == false)
            {
                seq = seq + 2; 
            }
        }

        int herustic = findDistance(0,s) + 3*(seq); 
        return herustic; 

    }

    void analyze1Child(string s, string ch1, int depth, string mthd)       // the following functions analyze 
    {
        insertParentArr(s, ch1);
        listofStates.push_back(ch1);

        queue1.push(ch1);
    }

    void analyze2Child(string s, string ch1, string ch2, int depth, string mthd)
    {
        insertParentArr(s, ch1);
        insertParentArr(s, ch2);

        listofStates.push_back(ch1);
        listofStates.push_back(ch2);

        if (mthd == "bestfirst1" || mthd == "bestfirst2" || mthd == "bestfirst3")
        {
            int ch1Val;
            int ch2Val;

            if (mthd == "bestfirst1")
            {
                ch1Val = findValue(depth, ch1);
                ch2Val = findValue(depth, ch2);
            }
            else if (mthd == "bestfirst2")
            {
                ch1Val = findDistance(depth, ch1);
                ch2Val = findDistance(depth, ch2);
            }
            else if (mthd == "bestfirst3")
            {
                ch1Val = findValueH(ch1, depth);
                ch2Val = findValueH(ch2, depth);
            }


            if (ch1Val < ch2Val)
            {
                queue1.push(ch1);
            }
            else if (ch2Val < ch1Val)
            {
                queue1.push(ch2);
            }
            else if (ch1Val == ch2Val)
            {
                queue1.push(ch1);
                queue1.push(ch2);
            }
        }


    }

    void analyze3Child(string s, string ch1, string ch2, string ch3, int depth, string mthd)
    {
        insertParentArr(s, ch1);
        insertParentArr(s, ch2);
        insertParentArr(s, ch3);

        listofStates.push_back(ch1);
        listofStates.push_back(ch2);
        listofStates.push_back(ch3);

        int ch1Val;
        int ch2Val;
        int ch3Val;

        if (mthd == "bestfirst1" || mthd == "bestfirst2" || mthd == "bestfirst3")
        {
            if (mthd == "bestfirst1")
            {
                ch1Val = findValue(depth, ch1);
                ch2Val = findValue(depth, ch2);
                ch3Val = findValue(depth, ch3);
            }
            else if (mthd == "bestfirst2")
            {
                ch1Val = findDistance(depth, ch1);
                ch2Val = findDistance(depth, ch2);
                ch3Val = findDistance(depth, ch3);
            }
            else if (mthd == "bestfirst3")
            {
                ch1Val = findValueH(ch1, depth);
                ch2Val = findValueH(ch2, depth);
                ch3Val = findValueH(ch3, depth);
            }

            if (ch1Val < ch2Val && ch1Val < ch3Val)
            {
                queue1.push(ch1);
            }
            else if (ch2Val < ch1Val && ch2Val < ch3Val)
            {
                queue1.push(ch2);
            }
            else if (ch3Val < ch1Val && ch3Val < ch2Val)
            {
                queue1.push(ch3);
            }
            else if (ch1Val == ch2Val && ch1Val == ch3Val)
            {
                queue1.push(ch1);
                queue1.push(ch2);
                queue1.push(ch3);
            }
            else if (ch1Val == ch2Val && ch1Val < ch3Val)
            {
                queue1.push(ch1);
                queue1.push(ch2);
            }
            else if (ch1Val == ch3Val && ch1Val < ch2Val)
            {
                queue1.push(ch1);
                queue1.push(ch3);
            }
            else if (ch2Val == ch3Val && ch2Val < ch1Val)
            {
                queue1.push(ch2);
                queue1.push(ch3);
            }
        }
    }

    void analyze4Child(string s, string ch1, string ch2, string ch3, string ch4, int depth, string mthd)     // alalyzes and develops and adds to the queue/stack for 4 children
    {
        cout << "RAN!" << endl;
        listofStates.push_back(ch1);
        listofStates.push_back(ch2);
        listofStates.push_back(ch3);
        listofStates.push_back(ch4);

        insertParentArr(s, ch1);
        insertParentArr(s, ch2);
        insertParentArr(s, ch3);
        insertParentArr(s, ch4);

        int ch1Val;
        int ch2Val;
        int ch3Val;
        int ch4Val;

        if (mthd == "bestfirst1" || mthd == "bestfirst2" || mthd == "bestfirst3")
        {
            if (mthd == "bestfirst1")
            {
                ch1Val = findValue(depth, ch1);
                ch2Val = findValue(depth, ch2);
                ch3Val = findValue(depth, ch3);
                ch4Val = findValue(depth, ch4);
            }
            else if (mthd == "bestfirst2")
            {
                ch1Val = findDistance(depth, ch1);
                ch2Val = findDistance(depth, ch2);
                ch3Val = findDistance(depth, ch3);
                ch4Val = findDistance(depth, ch4);
            }
            else if (mthd == "bestfirst3")
            {
                ch1Val = findValueH(ch1, depth);
                ch2Val = findValueH(ch2, depth);
                ch3Val = findValueH(ch3, depth);
                ch4Val = findValueH(ch4, depth);
            }


            if (ch1Val < ch2Val && ch1Val < ch3Val && ch1Val < ch4Val)
            {
                queue1.push(ch1);
            }
            else if (ch2Val < ch1Val && ch2Val < ch3Val && ch2Val < ch4Val)
            {
                queue1.push(ch2);
            }
            else if (ch3Val < ch1Val && ch3Val < ch2Val && ch3Val < ch4Val)
            {
                queue1.push(ch3);
            }
            else if (ch4Val < ch1Val && ch4Val < ch2Val && ch4Val < ch3Val)
            {
                queue1.push(ch4);
            }
            else if (ch1Val == ch2Val && ch1Val == ch3Val && ch1Val == ch4Val)
            {
                queue1.push(ch1);
                queue1.push(ch2);
                queue1.push(ch3);
                queue1.push(ch4);
            }
            else if (ch1Val == ch2Val && ch1Val < ch3Val && ch1Val < ch4Val)
            {
                queue1.push(ch1);
                queue1.push(ch2);
            }
            else if (ch1Val == ch3Val && ch1Val < ch2Val && ch1Val < ch4Val)
            {
                queue1.push(ch1);
                queue1.push(ch3);
            }
            else if (ch1Val == ch4Val && ch1Val < ch3Val && ch1Val < ch2Val)
            {
                queue1.push(ch1);
                queue1.push(ch4);
            }
            else if (ch1Val == ch2Val && ch2Val == ch3Val && ch1Val < ch4Val)
            {
                queue1.push(ch1);
                queue1.push(ch2);
                queue1.push(ch3);
            }
            else if (ch1Val == ch2Val && ch2Val == ch4Val && ch1Val < ch3Val)
            {
                queue1.push(ch1);
                queue1.push(ch2);
                queue1.push(ch4);
            }
            else if (ch1Val == ch3Val && ch1Val == ch4Val && ch1Val < ch2Val)
            {
                queue1.push(ch1);
                queue1.push(ch3);
                queue1.push(ch4);
            }
            else if (ch2Val == ch3Val && ch2Val == ch4Val && ch2Val < ch1Val)
            {
                queue1.push(ch2);
                queue1.push(ch3);
                queue1.push(ch4);
            }
            else if (ch2Val == ch3Val && ch2Val < ch1Val && ch2Val < ch4Val)
            {
                queue1.push(ch2);
                queue1.push(ch3);
            }
            else if (ch2Val == ch4Val && ch2Val < ch1Val && ch2Val < ch3Val)
            {
                queue1.push(ch2);
                queue1.push(ch4);
            }
            else if (ch3Val == ch4Val && ch3Val < ch1Val && ch3Val < ch2Val)
            {
                queue1.push(ch3);
                queue1.push(ch4);
            }

        }
    }

    void developChildren3(string s, int depth, string mthd)          // developing all possible children for breadth first method
    {
        //string zero = "0";
        if (s[0] == '0')
        {
            string ch1 = s;
            swap(ch1[0], ch1[3]);

            string ch2 = s;
            swap(ch2[0], ch2[1]);


            if (notInList(ch1))
            {
                if (notInList(ch2))
                    analyze2Child(s, ch1, ch2, depth, mthd);
                else
                    analyze1Child(s, ch1, depth, mthd);
            }
            else if (notInList(ch2))
                analyze1Child(s, ch2, depth, mthd);

        }
        else if (s[1] == '0')
        {
            string ch1 = s;
            swap(ch1[1], ch1[0]);

            string ch2 = s;
            swap(ch2[1], ch2[2]);

            string ch3 = s;
            swap(ch3[1], ch3[4]);


            if (notInList(ch1))
            {
                if (notInList(ch2) && notInList(ch3))
                {
                    analyze3Child(s, ch1, ch2, ch3, depth, mthd);
                }
                else if (notInList(ch2) && notInList(ch3)==false)
                {
                     analyze2Child(s, ch1, ch2, depth, mthd);
                }
                else if (notInList(ch3) && notInList(ch2)==false)
                {
                    analyze2Child(s, ch1, ch3, depth, mthd);
                }
                else
                {
                    analyze1Child(s, ch1, depth, mthd);
                }
            }
            else
            {
                if (notInList(ch2))
                {
                    if (notInList(ch3))
                    {
                        analyze2Child(s, ch2, ch3, depth, mthd);
                    }
                    else
                    {
                        analyze1Child(s, ch2, depth, mthd);
                    }
                }
                else if (notInList(ch3))
                {
                    analyze1Child(s, ch3, depth, mthd);
                }
            }



        }
        else if (s[2] == '0')
        {
            string ch1 = s;
            swap(ch1[2], ch1[1]);

            string ch2 = s;
            swap(ch2[2], ch2[5]);

            if (notInList(ch1))
            {
                if (notInList(ch2))
                    analyze2Child(s, ch1, ch2, depth, mthd);
                else
                    analyze1Child(s, ch1, depth, mthd);
            }
            else if (notInList(ch2))
                analyze1Child(s, ch2, depth, mthd);


        }
        else if (s[3] == '0')
        {
            string ch1 = s;
            swap(ch1[3], ch1[0]);

            string ch2 = s;
            swap(ch2[3], ch2[4]);

            string ch3 = s;
            swap(ch3[3], ch3[6]);

            if (notInList(ch1))
            {
                if (notInList(ch2) && notInList(ch3))
                {
                    analyze3Child(s, ch1, ch2, ch3, depth, mthd);
                }
                else if (notInList(ch2) && notInList(ch3)==false)
                {
                     analyze2Child(s, ch1, ch2, depth, mthd);
                }
                else if (notInList(ch3) && notInList(ch2)==false)
                {
                    analyze2Child(s, ch1, ch3, depth, mthd);
                }
                else
                {
                    analyze1Child(s, ch1, depth, mthd);
                }
            }
            else
            {
                if (notInList(ch2))
                {
                    if (notInList(ch3))
                    {
                        analyze2Child(s, ch2, ch3, depth, mthd);
                    }
                    else
                    {
                        analyze1Child(s, ch2, depth, mthd);
                    }
                }
                else if (notInList(ch3))
                {
                    analyze1Child(s, ch3, depth, mthd);
                }
            }
        }
        else if (s[4] == '0')
        {
            string ch1 = s;
            swap(ch1[4], ch1[3]);

            string ch2 = s;
            swap(ch2[4], ch2[1]);

            string ch3 = s;
            swap(ch3[4], ch3[5]);

            string ch4 = s;
            swap(ch4[4], ch4[7]);

            if (notInList(ch1))
            {
                if (notInList(ch2) && notInList(ch3) && notInList(ch4))
                {
                    analyze4Child(s, ch1, ch2, ch3, ch4, depth, mthd);
                }
                else if (notInList(ch2) && notInList(ch3) && notInList(ch4)==false)
                {
                     analyze3Child(s, ch1, ch2, ch3, depth, mthd);
                }
                else if (notInList(ch2) && notInList(ch3)==false && notInList(ch4))
                {
                    analyze3Child(s, ch1, ch2, ch4, depth, mthd);
                }
                else if (notInList(ch2)==false && notInList(ch3) && notInList(ch4))
                {
                    analyze3Child(s, ch1, ch3, ch4, depth, mthd);
                }
                else if (notInList(ch2)==false && notInList(ch3)==false && notInList(ch4))
                {
                    analyze2Child(s, ch1, ch4, depth, mthd);
                }
                else if (notInList(ch2)==false && notInList(ch3) && notInList(ch4)==false)
                {
                    analyze2Child(s, ch1, ch3, depth, mthd);
                }
                else if (notInList(ch2) && notInList(ch3)==false && notInList(ch4)==false)
                {
                    analyze2Child(s, ch1, ch2, depth, mthd);
                }
                else
                {
                    analyze1Child(s, ch1, depth, mthd);
                }
            }
            else if (notInList(ch2))
            {
                if (notInList(ch3) && notInList(ch4))
                {
                    analyze3Child(s, ch2, ch3, ch4, depth, mthd);
                }
                else if (notInList(ch3)==false && notInList(ch4))
                {
                    analyze2Child(s, ch2, ch4, depth, mthd);
                }
                else if (notInList(ch3) && notInList(ch4)==false)
                {
                    analyze2Child(s, ch2, ch3, depth, mthd);
                }
                else
                {
                    analyze1Child(s, ch2, depth, mthd);
                }
            }
            else if (notInList(ch3))
            {
                if (notInList(ch4))
                {
                    analyze2Child(s, ch3, ch4, depth, mthd);
                }
                else
                {
                    analyze1Child(s, ch3, depth, mthd);
                }
            }
            else if (notInList(ch4))
            {
                analyze1Child(s, ch4, depth, mthd);
            }


        }
        else if (s[5] == '0')
        {
            string ch1 = s;
            swap(ch1[5], ch1[4]);

            string ch2 = s;
            swap(ch2[5], ch2[2]);

            string ch3 = s;
            swap(ch3[5], ch3[8]);

            if (notInList(ch1))
            {
                if (notInList(ch2) && notInList(ch3))
                {
                    analyze3Child(s, ch1, ch2, ch3, depth, mthd);
                }
                else if (notInList(ch2) && notInList(ch3)==false)
                {
                     analyze2Child(s, ch1, ch2, depth, mthd);
                }
                else if (notInList(ch3) && notInList(ch2)==false)
                {
                    analyze2Child(s, ch1, ch3, depth, mthd);
                }
                else
                {
                    analyze1Child(s, ch1, depth, mthd);
                }
            }
            else
            {
                if (notInList(ch2))
                {
                    if (notInList(ch3))
                    {
                        analyze2Child(s, ch2, ch3, depth, mthd);
                    }
                    else
                    {
                        analyze1Child(s, ch2, depth, mthd);
                    }
                }
                else if (notInList(ch3))
                {
                    analyze1Child(s, ch3, depth, mthd);
                }
            }
        }
        else if (s[6] == '0')
        {
            string ch1 = s;
            swap(ch1[6], ch1[3]);

            string ch2 = s;
            swap(ch2[6], ch2[7]);

            if (notInList(ch1))
            {
                if (notInList(ch2))
                    analyze2Child(s, ch1, ch2, depth, mthd);
                else
                    analyze1Child(s, ch1, depth, mthd);
            }
            else if (notInList(ch2))
                analyze1Child(s, ch2, depth, mthd);


        }
        else if (s[7] == '0')
        {
            string ch1 = s;
            swap(ch1[7], ch1[6]);

            string ch2 = s;
            swap(ch2[7], ch2[4]);

            string ch3 = s;
            swap(ch3[7], ch3[8]);

            if (notInList(ch1))
            {
                if (notInList(ch2) && notInList(ch3))
                {
                    analyze3Child(s, ch1, ch2, ch3, depth, mthd);
                }
                else if (notInList(ch2) && notInList(ch3)==false)
                {
                     analyze2Child(s, ch1, ch2, depth, mthd);
                }
                else if (notInList(ch3) && notInList(ch2)==false)
                {
                    analyze2Child(s, ch1, ch3, depth, mthd);
                }
                else
                {
                    analyze1Child(s, ch1, depth, mthd);
                }
            }
            else
            {
                if (notInList(ch2))
                {
                    if (notInList(ch3))
                    {
                        analyze2Child(s, ch2, ch3, depth, mthd);
                    }
                    else
                    {
                        analyze1Child(s, ch2, depth, mthd);
                    }
                }
                else if (notInList(ch3))
                {
                    analyze1Child(s, ch3, depth, mthd);
                }
            }
        }
        else if (s[8] == '0')
        {
            string ch1 = s;
            swap(ch1[8], ch1[7]);

            string ch2 = s;
            swap(ch2[8], ch2[5]);

            if (notInList(ch1))
            {
                if (notInList(ch2))
                    analyze2Child(s, ch1, ch2, depth, mthd);
                else
                    analyze1Child(s, ch1, depth, mthd);
            }
            else if (notInList(ch2))
                analyze1Child(s, ch2, depth, mthd);

        }
    }


    void bestFirstSearch1(string s1, int option)    // uses queue and the define methods in the assignemnt 
    {
        queue1.push(s1);
        insertParentArr("NULL", s1);
        listofStates.push_back(s1);
        int depth = 0;

        string foundAns = "";

        while ((queue1.empty() == false) && (listofStates.size() < 362881)) //&& (depth < 25))       // making sure stack is not empty and controling search through max depth
        {
            string s = queue1.front();
            queue1.pop();

            if (s == goal)
            {
                foundAns = s;
                break;
            }
            else
            {
                //depth = depth + 1;
                if (option == 1)
                {
                    developChildren3(s, depth, "bestfirst1");
                }
                else if (option == 2)
                {
                    developChildren3(s, depth, "bestfirst2");
                }
                else if (option == 3)
                {
                    developChildren3(s, depth, "bestfirst3"); 
                }


                //cout <<" Generated states: " << listofStates.size() << " / 362880" << endl; // remove later

            }

        }

        if (foundAns == goal && listofStates.size() < 32000)
        {

            pathtoFinal.push_back(foundAns);

            pathtoGoal(foundAns);

            cout << endl;
            cout << "Path to goal state:" << endl << endl;

            for(int i=(pathtoFinal.size())-2; i>-1; i--)
            {
                if (i==0)
                {
                    printboard(pathtoFinal[i]);
                }
                else
                {
                    printboard(pathtoFinal[i]); 

                    cout << "       | " << endl; 
                    cout << "       V " << endl;
                }
            }

        }
        else
        {
            cout << "Insufficient array memory: Too many (over 35,000) generated states to hold in array and print path." << endl;
        }


        cout << endl;
        cout << "The minimum number of moves required: " << pathtoFinal.size() - 2 << endl;
        cout << "The total number of generated nodes are: " << listofStates.size() << endl << endl;

    }

};









int main()
{
    cout << endl;
    cout << "*========================================= WELCOME =========================================*" << endl << endl;

    Node n1;

    string b = "283164705";    // user input
    string a = "134802765";
    string c = "216408753";

    
    cout << "Instructions: 1) enter only values from [0-8]" << endl; 
    cout << "              2) each value should be entered only once." << endl;
    cout << "              3) use '0' to represent the space character when inserting initial state." << endl;
    cout << "              3) select search method." << endl << endl;

    cout << "String input of '283164705' represents the following tile" << endl;

    n1.printboard("283164705"); 

    cout << endl;
    cout << "Enter the initial state for the tile: "; 
    string input; 
    cin >> input; 
    cout << endl;

    if (input.size() == 9)
    {
        cout << "     Depth First Search method                            ---> choose (1)" << endl;
        cout << "     Breadth First Search method                          ---> choose (2)" << endl;
        cout << "     Best First Search - tiles out of place method        ---> choose (3)" << endl;
        cout << "     Best First Search - min. moves to goal state method  ---> choose (4)" << endl;
        cout << "     Best First Search - Heuristic H method               ---> choose (5)" << endl << endl;
        
        cout << "Enter the search method: "; 
        int option; 
        cin >> option; 
        cout << endl;

        if (option == 1)
        {
            n1.depthFirstSearch(input);
        }
        else if (option == 2)
        {
            n1.breadthFirstSearch(input);
        }
        else if (option == 3)
        {
            n1.bestFirstSearch1(input, 1);  // based on the number of values out of place.
        }
        else if (option == 4)
        {
            n1.bestFirstSearch1(input, 2);    // based on mininmum number of moves to reach goal state.
        }
        else if (option == 5)
        {
            n1.bestFirstSearch1(input, 3);    // based on mininmum number of moves to reach goal state.
        }

    }
    else 
    {
        cout << "Input error: make sure to enter only nine digits from [0-8]" << endl; 
    }





    cout << endl;
    cout << "*========================================= END =========================================*" << endl << endl;


    return 0;
}