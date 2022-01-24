class Solution {
public:
    bool checkCycle(int start, bool checkPrequisite[], bool visitDFS[], vector<int> graph[]){
             checkPrequisite[start] = true;
             visitDFS[start] = true;
                
             for(auto i : graph[start]){
                   if(!checkPrequisite[i]){   
                          if(checkCycle(i, checkPrequisite, visitDFS, graph))
                                 return true;
                      }
                    else if(visitDFS[i])
                           return true;
             }
            
        visitDFS[start] = false;
        return false;
   }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      
        bool checkPrequisite[numCourses] , visitDFS[numCourses];
        
        memset (checkPrequisite, false, sizeof checkPrequisite);
        memset (visitDFS, false, sizeof visitDFS);
        
        vector<int> graph[numCourses];
        
        // creating a graph using prerequisites
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
         for(int i = 0; i < numCourses; i++){
            if(!checkPrequisite[i]){
                if(checkCycle(i, checkPrequisite, visitDFS, graph))     // if cycle exists we can't finish all courses
                    return false;
            }
        }
        return true;
        
    }
};