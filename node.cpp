#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

bool inside(vector<int> n, vector<double> m){
    double x = n[0];double y = n[1];
    if((n[0] >= 90 && n[1] <= 30) || (n[0] >= 180 && n[1] >= 30 && n[1] <= 50))
        return false;

    if(n[0]<=30 && n[1]>=60){
        double s = (y-60) / x;
        if(s > m[0])
            return false;
    }
    else if(n[0]<60 && n[1] <= 60){
        double s = y / (x-60);
        if(s > m[1])
            return false;
    }
    else if(n[0]>=60 && n[0]<=90 && n[1]<=30){
        double s = y / (x-60);
        if(s < m[2])
            return false;
    }
    else if(n[0] >= 90 && n[0] <= 180 && n[1] <= 50){
        double s = (y-30) / (x-90);
        if(s < m[3])
            return false;
    }
    else if(n[0]>=180 && n[1] <=80){
        double s = (y-50) / (x-180);
        if(s < m[4])
            return false;
    }
    else if(n[0]>=170 && n[1] >= 80){
        double s = (y-80) / (x-200);
        if(s < m[5])
            return false;
    }
    else if(n[0] >= 100 && n[0] <= 170 && n[1] >= 70){
        double s = (y-70) / (x-100);
        if(s > m[6])
            return false;
    }
    else if(n[0]>=30 && n[0] <= 100 && n[1] >= 70){
        double s = (y-70) / (x-100);
        if(s < m[7])
            return false;
    }
    return true;
}

void initialize(set<vector<int>> &region, set<vector<int>> &node, vector<int> &n){
    n[0] = 30;n[1] = 70;n[2] = 0;
    node.insert(n);
    region.insert(n);
    n[0] = 55;n[1] = 40;n[2] = 0;
    node.insert(n);
    region.insert(n);
    n[0] = 60;n[1] = 15;n[2] = 0;
    node.insert(n);
    region.insert(n);
    n[0] = 100;n[1] = 60;n[2] = 0;
    node.insert(n);
    region.insert(n);
    n[0] = 160;n[1] = 70;n[2] = 0;
    node.insert(n);
    region.insert(n);
}

int identity(set<vector<int>> &region, vector<int> &n){
    set<vector<int>>::iterator it;
    for(it = region.begin(); it != region.end();it++){
        const vector<int> &i = (*it);
        double distance = sqrt(pow(i[0]-n[0],2)+pow(i[1]-n[1],2));
        if(distance <= 15)
            return 1;
    }
    return 2;
}

void connect(set<vector<int>> &node, char* coordinate_file, char* connect_file){
    ofstream file,file1;
    file.open(connect_file, ios_base::app);
    file1.open(coordinate_file, ios_base::app);
    int nodenum = 0;
    set<vector<int>>::iterator i,j;
    for(i = node.begin(); i != node.end(); i++){
        nodenum+=1;
        const vector<int> &one = (*i);
        int nnum = 0;
        switch(one[2]){
            case 0:
                for(j = node.begin(); j != node.end(); j++){
                    nnum += 1;
                    const vector<int> &other = (*j);
                    if(i != j){
                        switch(other[2]){
                            case 0:
                                if(sqrt(pow(other[0]-one[0],2)+pow(other[1]-one[1],2)) <= 50){
                                    file << nodenum-1 << " " << nnum-1 << endl;
                                    file1 << one[0] << " " << one[1] << " " << other[0] << " " << other[1] << endl;
                                }
                                break;
                            case 1:
                                if(sqrt(pow(other[0]-one[0],2)+pow(other[1]-one[1],2)) <= 40){
                                    file << nodenum-1 << " " << nnum-1 << endl;
                                    file1 << one[0] << " " << one[1] << " " << other[0] << " " << other[1] << endl;
                                }
                                break;
                            case 2:
                                if(sqrt(pow(other[0]-one[0],2)+pow(other[1]-one[1],2)) <= 30){
                                    file << nodenum-1 << " " << nnum-1 << endl;
                                    file1 << one[0] << " " << one[1] << " " << other[0] << " " << other[1] << endl;
                                }
                                break;
                        }
                    }
                }
                break;
            case 1:
                for(j = node.begin(); j != node.end(); j++){
                    nnum += 1;
                    const vector<int> &other = (*j);
                    if(i != j){
                        switch(other[2]){
                            case 1:
                                if(sqrt(pow(other[0]-one[0],2)+pow(other[1]-one[1],2)) <= 40){
                                    file << nodenum-1 << " " << nnum-1 << endl;
                                    file1 << one[0] << " " << one[1] << " " << other[0] << " " << other[1] << endl;
                                }
                                break;
                            case 2:
                                if(sqrt(pow(other[0]-one[0],2)+pow(other[1]-one[1],2)) <= 25){
                                    file << nodenum-1 << " " << nnum-1 << endl;
                                    file1 << one[0] << " " << one[1] << " " << other[0] << " " << other[1] << endl;
                                }
                                break;
                        }
                    }
                }
                break;
            case 2:
                for(j = node.begin(); j != node.end(); j++){
                    nnum += 1;
                    const vector<int> &other = (*j);
                    if(i != j && other[2] == 2){
                        if(sqrt(pow(other[0]-one[0],2)+pow(other[1]-one[1],2)) <= 10){
                            file << nodenum-1 << " " << nnum-1 << endl;
                            file1 << one[0] << " " << one[1] << " " << other[0] << " " << other[1] << endl;
                        }
                    }
                }
                break;
        }
    }
    file.close();file1.close();
}

int ArgPos(char* str, int argc, char** argv){
    int a;

    for(a = 1 ; a < argc ; a++) if (!strcmp(str, argv[a])){
        if(a == argc - 1){
            cout << "Argument missing for " << str << std::endl;
            exit(1);
        }

        return a;
    }

    return -1;
}


int main(int argc, char** argv){
    vector<pair<double,double>> boundary;
    vector<double> m;
    boundary.push_back(make_pair(30,100));
    boundary.push_back(make_pair(0,60));
    boundary.push_back(make_pair(60,0));
    boundary.push_back(make_pair(90,30));
    boundary.push_back(make_pair(180,50));
    boundary.push_back(make_pair(200,80));
    boundary.push_back(make_pair(170,100));
    boundary.push_back(make_pair(100,70));

    double slope;
    vector<pair<double,double>>::iterator iter;
    for(iter=boundary.begin() ; (iter+1)!=boundary.end() ; iter++){
        slope = ((*iter).second - (*(iter+1)).second) / ((*iter).first - (*(iter+1)).first);
        m.push_back(slope);
    }
    slope = (boundary[0].second - boundary[7].second) / (boundary[0].first - boundary[7].first);
    m.push_back(slope);
/*    for(int i=0;i<8;++i)
        cout << "m=" << m[i] << endl;
*/

    int i;
    char* node_file = new char[20];
    char* connect_file = new char[20];
    char* coordinate_file = new char[20];
    int n_index = 0;long seed = 0;
    strcpy(node_file, "");strcpy(coordinate_file, "");strcpy(connect_file, "");

    if((i = ArgPos((char*)"-n_index", argc, argv)) > 0) n_index = atoi(argv[i+1]);
    if((i = ArgPos((char*)"-seed", argc, argv)) > 0) seed = atoi(argv[i+1]);
    if((i = ArgPos((char*)"-node_file", argc, argv)) > 0) strcpy(node_file, argv[i + 1]);
    if((i = ArgPos((char*)"-coordinate_file", argc, argv)) > 0) strcpy(coordinate_file, argv[i + 1]);
    if((i = ArgPos((char*)"-connect_file", argc, argv)) > 0) strcpy(connect_file, argv[i + 1]);

    cout << node_file << " " << coordinate_file << " " << connect_file << endl;
    srand(seed);
    set<vector<int>> node,region;
    vector<int> n(3);
    initialize(node,region,n);

    while(node.size() < n_index){
        int x = rand()%200;
        int y = rand()%100;
        n[0] = x;
        n[1] = y;
//        cout << n[0] << " " << n[1] << endl;
        if(inside(n,m)==true){
            n[2] = identity(region,n);
            node.insert(n);
        }
//        cout << "hi=" << node.size() << endl;
    }

    if(strcmp(node_file,"") != 0){
        ofstream file;
        file.open(node_file, ios_base::app);

        set<vector<int>>::iterator it;
        for(it = node.begin(); it != node.end();it++){
            const vector<int> &i = (*it);
            file << i[0] << " " << i[1] << " " << i[2] << endl;
        }
        file.close();
    }
    if(strcmp(coordinate_file,"") != 0 && strcmp(connect_file,"") != 0)
        connect(node,coordinate_file,connect_file);

    return 0;
}
