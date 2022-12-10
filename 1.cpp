#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int dr[5] = {0,1,0,-1,0};

void dfs(vector<vector<int>> image,vector<vector<int>> &vis,int i,int j,vector<int> res){
    int m = image.size(), n =image[0].size();
    if(i<0 || j<0 || i>=m || j>=n || vis[i][j]==1) return ;
    
    vis[i][j]=1;
    res[0]=min(res[0],i);
    res[1]=min(res[1],j);
    res[2]=max(res[2],i);
    res[3]=max(res[3],j);
    
    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            int new_x=i+dx, new_y=j+dy;
            if(!(new_x!=i && new_y!=j)){
                if(vis[new_x][new_y]==0){
                    dfs(image,vis,new_x,new_y,res);
                }
            }
        }
    }
}

int main() {
    int n,m;
    cout<<"Enter Dimensions of the image:"<<endl;
    cin>>m>>n;
    vector<vector<int>> image(m,vector<int>(n,0));
    cout<<"Enter Image:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>image[i][j];
        }
    }
    
    //idea is to do the dfs traversal in all 8 directions in the image and for a white object find the four variables
    // min row number, max row number and min column number , max column number
    // using these four variables, we can find height, width and midX,midY
    vector<vector<int>> vis(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j] == 0 && image[i][j]==0){
                int minx = 1e9,miny=1e9,maxx=-1,maxy=-1;
                vector<int> res={minx, miny, maxx,maxy};
                dfs(image,vis,i,j,res);
                float midX,midY;
                int h,w;
                midX=(res[0]+res[2])/2.0;
                midY=(res[1]+res[3])/2.0;
                h=abs(res[0]-res[2]);
                w=abs(res[1]-res[3]);
                cout<<midX<<" "<<midY<<" "<<h<<" "<<w<<endl;
            }
            
            
        }
    }
    return 0;
}
