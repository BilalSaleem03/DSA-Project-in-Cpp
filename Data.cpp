#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

//Node creation for Link List implementation
struct Node
{
    string playerName;
    int matches;
    int runs;
    int centuries;
    double average;
    Node *next ;
    Node *pre;
    Node(string n , int r , int m , int c , double a)
    {
        playerName = n;
        matches = m;
        runs = r;
        centuries = c;
        average = a;
        next = NULL;
        pre = NULL;
    }
};
struct Node *head = NULL;
struct Node *tail = NULL;

void addNode(string n , int r , int m , int c , double a)
{
    Node* newNode = new Node(n , r , m , c , a);

    if(head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->pre = tail;
        tail = newNode;
    }
}

//Node creation for BST implementation
struct BSTNode
{
    string playerName;
    int matches;
    int runs;
    int centuries;
    double average;
    BSTNode *left ;
    BSTNode *right;
    BSTNode(string n , int r , int m , int c , double a)
    {
        playerName = n;
        matches = m;
        runs = r;
        centuries = c;
        average = a;
        left = NULL;
        right = NULL;
    }
};
struct BSTNode *BSTroot = NULL;

BSTNode* rightRotate(BSTNode* n)
{
    BSTNode* nLeft = n->left;
    BSTNode* nLeftRight = nLeft->right;

    nLeft->right = n;
    n->left = nLeftRight;
    return nLeft;
}

BSTNode* leftRotate(BSTNode* n)
{
    BSTNode* nRight = n->right;
    BSTNode* nRightLeft = nRight->left;

    nRight->left = n;
    n->right = nRightLeft;
    return nRight;
}

int heightOfTree(BSTNode* r)
{
    if(r == NULL)
    {
        return 0;
    }
    int leftheight = heightOfTree(r->left);
    int rightheight = heightOfTree(r->right);
    return (max(leftheight , rightheight)+1);
}

int getBalanceFactor(BSTNode* n)
{
    return (heightOfTree(n->left) - heightOfTree(n->right));
}

BSTNode* addNodeInBST(BSTNode* BSTroot , string n , int r , int m , int c , double a)
{
    if(BSTroot == NULL)
    {
        BSTNode* newNode = new BSTNode(n , r , m , c , a);
        return newNode;
    }
    else if(BSTroot->average > a)
    {
        BSTroot->left = addNodeInBST(BSTroot->left , n , r , m , c , a);
    }
    else if(BSTroot->average < a)
    {
        BSTroot->right = addNodeInBST(BSTroot->right , n , r , m , c , a);
    }

    int balanceFactor = getBalanceFactor(BSTroot);

    // left left
    if(balanceFactor > 1 && a < BSTroot->left->average)
    {
        return rightRotate(BSTroot);
    }
    //right right
    if(balanceFactor < -1 && a > BSTroot->right->average)
    {
        return leftRotate(BSTroot);
    }
    //left right
    if(balanceFactor > 1 && a > BSTroot->left->average)
    {
        BSTroot->left = leftRotate(BSTroot->left);
        return rightRotate(BSTroot);
    }
    //right left
    if(balanceFactor < -1 && a < BSTroot->right->average)
    {
        BSTroot->right = rightRotate(BSTroot->right);
        return leftRotate(BSTroot);
    }

    return BSTroot;
}


void printAll()
{
    Node* temp = head;
    int count = 1;
    cout<<"Name         ,   Matches  ,    Runs  ,     Average  ,    centuries "<<endl<<endl;
    while(temp != NULL)
    {
        cout<<count<<") "<<temp->playerName<<"  ,  "<<temp->matches<<"  ,  "<<temp->runs<<"  ,   "<<temp->average<<"  ,  "<<temp->centuries<<endl;
        count++;
        temp = temp->next;
    }
}

void printByMatches()
{
    Node* temp = head;
    int mat;
    cout<<"Enter Matches above which to display : "<<endl;
    cin>>mat;
    bool check = true;
    int count = 1;
    cout<<"Name         ,   Matches  ,    Runs  ,     Average  ,    centuries "<<endl<<endl;
    while(temp != NULL)
    {
        if(temp->matches > mat)
        {
            check = false;
            cout<<count<<") "<<temp->playerName<<"  ,  "<<temp->matches<<"  ,  "<<temp->runs<<"  ,   "<<temp->average<<"  ,  "<<temp->centuries<<endl;
            count++;
        }

        temp = temp->next;
    }
    if(check)
    {
        cout<<"No Data Found!!!!!"<<endl;
    }
}

void printByAverage()
{
    Node* temp = head;
    double av;
    cout<<"Enter average above which to display : "<<endl;
    cin>>av;
    bool check = true;
    int count = 1;
    cout<<"Name         ,   Matches  ,    Runs  ,     Average  ,    centuries "<<endl<<endl;
    while(temp != NULL)
    {
        if(temp->average > av)
        {
            check = false;
            cout<<count<<") "<<temp->playerName<<"  ,  "<<temp->matches<<"  ,  "<<temp->runs<<"  ,   "<<temp->average<<"  ,  "<<temp->centuries<<endl;
            count++;
        }

        temp = temp->next;
    }
    if(check)
    {
        cout<<"No Data Found!!!!!"<<endl;
    }
}

void printByRuns()
{
    Node* temp = head;
    int run;
    cout<<"Enter Runs above which to display : "<<endl;
    cin>>run;
    bool check = true;
    int count = 1;
    cout<<"Name         ,   Matches  ,    Runs  ,     Average  ,    centuries "<<endl<<endl;
    while(temp != NULL)
    {
        if(temp->runs > run)
        {
            check = false;
            cout<<count<<") "<<temp->playerName<<"  ,  "<<temp->matches<<"  ,  "<<temp->runs<<"  ,   "<<temp->average<<"  ,  "<<temp->centuries<<endl;
            count++;
        }

        temp = temp->next;
    }
    if(check)
    {
        cout<<"No Data Found!!!!!"<<endl;
    }
}

void printByName()
{
    Node* temp = head;
    string n;
    cout<<"Enter Player Name to display : "<<endl;
    cin>>n;
    bool check = true;
    cout<<"Name         ,   Matches  , Runs , Average , centuries "<<endl;
    while(temp != NULL)
    {
        if(temp->playerName == n)
        {
            check = false;
            cout<<temp->playerName<<"  ,  "<<temp->matches<<"  ,  "<<temp->runs<<"  ,   "<<temp->average<<"  ,  "<<temp->centuries<<endl;
            break;
        }
        temp = temp->next;
    }
    if(check)
    {
        cout<<"No Data Found!!!!!"<<endl;
    }

}

void deleteByName()
{
    Node* temp = head;
    string n;
    cout<<"Enter Player Name to display : "<<endl;
    cin>>n;
    bool check = true;
    while(temp != NULL)
    {
        if(temp->playerName == n)
        {
            Node* t = temp;
            check = false;
            if(temp == head)
            {
                head = head->next;
                head->pre = NULL;
                delete(t);
            }
            else if(temp == tail)
            {
                tail = tail->pre;
                tail->next = NULL;
                delete(t);
            }
            else
            {
                temp->pre->next = temp->next;
                temp->next->pre = temp->pre;
                delete(temp);

            }
            cout<<"Player is deleted "<<endl;
            break;
        }
        temp = temp->next;
    }
    if(check)
    {
        cout<<"No Data Found!!!!!"<<endl;
    }
}

void addNewPlayer()
{
    string name;
    int matches , runs , centuries;
    double avg;
    cout<<"Enter name : "<<endl;
    cin>>name;
    cout<<"Enter Matches : "<<endl;
    cin>>matches;
    cout<<"Enter runs : "<<endl;
    cin>>runs;
    cout<<"Enter centuries : "<<endl;
    cin>>centuries;
    cout<<"Enter Average : "<<endl;
    cin>>avg;

    Node* newNode = new Node(name , runs , matches , centuries , avg);

    //fing position
    bool check = true;
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->runs < runs)
        {
            if(temp == head)
            {
                temp->pre = newNode;
                newNode->next = temp;
                head = newNode;
                check = false;
                break;
            }
            else
            {
                temp->pre->next = newNode;
                newNode->pre = temp->pre;
                temp->pre = newNode;
                newNode->next = temp;
                break;
            }
            //check = false;
        }
        temp = temp->next;
    }
    if(temp == NULL)
    {
        tail->next = newNode;
        newNode->pre = tail;
        tail = newNode;
    }
}

void printNode(Node* temp)
{
    cout<<temp->playerName<<"  ,  "<<temp->matches<<"  ,  "<<temp->runs<<"  ,   "<<temp->average<<"  ,  "<<temp->centuries<<endl;
}

void reversePrint()  //stack used
{
    stack<Node*> st;
    Node* temp = head;
    while(temp != NULL)
    {
        st.push(temp);
        temp = temp->next;
    }
    while(!st.empty())
    {
        printNode(st.top());
        st.pop();
    }
}

queue<Node*> q;
void addInQueue()
{
    Node* temp = head;
    while(temp != NULL)
    {
        q.push(temp);
        temp = temp->next;
    }
}

stack<Node*> stk;
void addSortedly(Node* n)
{
    if(stk.empty() || stk.top()->matches <= n->matches)
    {
        stk.push(n);
        return;
    }
    Node* temp = stk.top();
    stk.pop();
    addSortedly(n);
    stk.push(temp);
}

void sortingByMatches() //making priority queue using stack
{ 
    if(q.empty())
    {
        return;
    }
    Node* x = q.front();
    q.pop();
    sortingByMatches();
    addSortedly(x);
}

void printSortedlyByMatches()
{
    while(!stk.empty())
    {
        cout<<stk.top()->playerName<<"  ,  "<<stk.top()->matches<<"  ,  "<<stk.top()->runs<<"  ,   "<<stk.top()->average<<"  ,  "<<stk.top()->centuries<<endl;;
        stk.pop();
    }
}

void averageRunsInDataSet()
{
    Node* temp = head;
    long totalRuns = 0;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        totalRuns+= temp->runs;
        temp = temp->next;
    }
    cout<<"Average Runs are : "<<(totalRuns/count)<<endl;
}

void inorder(BSTNode* BSTroot)
{
    if(BSTroot == NULL)
    {
        return;
    }  
    inorder(BSTroot->left);
    cout<<BSTroot->playerName<<"  ,  "<<BSTroot->matches<<"  ,  "<<BSTroot->runs<<"  ,   "<<BSTroot->average<<"  ,  "<<BSTroot->centuries<<endl;
    inorder(BSTroot->right);  
}

bool searchByAverage(BSTNode* BSTroot , double avg)
{
    if(BSTroot == NULL)
    {
        cout<<"Data not Found!!!!!!!!!"<<endl;
        return false;
    }
    else if(BSTroot->average == avg)
    {
        cout<<"Data Found.......Its>>>"<<endl;
        cout<<BSTroot->playerName<<"  ,  "<<BSTroot->matches<<"  ,  "<<BSTroot->runs<<"  ,   "<<BSTroot->average<<"  ,  "<<BSTroot->centuries<<endl;
        return true;
    }
    else if(BSTroot->average < avg)
    {
        return searchByAverage(BSTroot->right , avg);
    }
    else if(BSTroot->average > avg)
    {
        return searchByAverage(BSTroot->left , avg);
    }
}

//hashing...
void frequencyOfCenturies(int hArr[] , int cen)
{
    if(hArr[cen] == 0)
    {
        cout<<"No player has that frequncy of Centuries"<<endl;
        return;
    }
    
    cout<<"Total of "<<hArr[cen]<<" players have "<<cen<<" centuries"<<endl;

}


int main()
{
    ifstream csvFile;
    csvFile.open("ODIdata.csv");



    string line , word;
    vector<string> vec;


    while(!csvFile.eof())
    {
        getline(csvFile , line);
        stringstream s(line);
        while(getline(s,word,','))
        {
            vec.push_back(word);
        }

        //type casting of needed coulumns.......

        int matches;
        stringstream ms(vec[3]);
        ms>>matches;

        int runs;
        stringstream rs(vec[6]);
        rs>>runs;

        double avg;
        stringstream as(vec[8]);
        as>>avg;

        int centuries;
        stringstream cs(vec[11]);
        cs>>centuries;

        // add data to Node and create link list

        addNode(vec[1] , runs , matches, centuries , avg );

        // add data to BSTNode and create BST

        BSTroot = addNodeInBST(BSTroot , vec[1] , runs , matches, centuries , avg );

        //clearvector

        vec.clear();
    }
    Node* n = tail;
    tail = tail->pre;
    tail->next = NULL;
    
    delete(n);

    int hashingArr[1000];        //Array for Hashing
    for(int i = 0 ;i<1000 ; i++)
    {
        hashingArr[i] = 0;
    }
    
    Node* tempp = head;
    while(tempp != NULL)
    {
        hashingArr[tempp->centuries]++;
        tempp = tempp->next;
    }


    int choice;
    while(true)
    {
        cout<<"Enter \n 1 to print All Players Data \n 2 to print Data w.r.t Matches played \n 3 to print Data w.r.t Average \n 4 to print Data w.r.t Runs \n 5 to get data of particular Player \n 6 to Add New Player \n 7 to print from lowest to hightest Runs Made \n 8 to Print from Most to Least Matches Played \n 9 to delete Player by name \n 10 to get Average runs for Data Set players\n 11 to sort by average using BST \n 12 search player by average using BST \n 13 to find frequency of centuries(Hashing) \n Any other integer to exit "<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
            printAll();
            break;

            case 2:
            printByMatches();
            break;

            case 3:
            printByAverage();
            break;

            case 4:
            printByRuns();
            break;

            case 5:
            printByName();
            break;

            case 6:
            addNewPlayer();
            break;

            case 7:
            reversePrint();  //stacks use  //already sorted by runs made
            break;

            case 8:
            addInQueue();    // queues use
            sortingByMatches();
            printSortedlyByMatches();
            break;

            case 9:
            deleteByName();
            break;

            case 10:
            averageRunsInDataSet();
            break;

            case 11:
            cout<<"Name     ,   Matches  ,    Runs  ,     Average  ,    centuries "<<endl<<endl;
            inorder(BSTroot);  //BST use
            break;

            case 12:
            cout<<"Enter average to search : "<<endl;  //BST use
            double avg;
            cin>>avg;
            searchByAverage(BSTroot , avg);
            break;

            case 13:
            cout<<"Enter centuries for which frequency is rquired :"<<endl;
            int c;
            cin>>c;
            frequencyOfCenturies(hashingArr , c);
            break;

            default:
            cout<<"Program Terminates!!!!"<<endl;
            exit(0);

        }
    }
    return 0;
}