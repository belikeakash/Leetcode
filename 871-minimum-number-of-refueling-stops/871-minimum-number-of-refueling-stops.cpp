class Solution {
public:
    #define ull unsigned long long
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        vector<vector<ull>> t(n+1, vector<ull>(n+1, 0));
        //t[i][j] = Maximum distance reached if I stopped at 'j' fuelStops from total of 'i' fuelStops
        //i.e. j <= i
        
        //If j = 0, i.e. I did not use any fuelStops, Then maximum I can reach is 'startFuel' which I had initially
        
        //So, initialize the dp array with this information
        for(int i = 0; i<n+1; i++) {
            t[i][0] = startFuel;
        }
        
        //There is no point of filling 1st row because 
        //t[0][j] means I used j fuelStops from 0 fuelStops which doesn't make any sense for (j>0)
        //That's why I start from i = 1 and obviously j = 1 because for j = 0 we already populated the dp array
        
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j <= i; j++) { //I can use j=1 to j=i fuel stops and find max distance for t[i][j]
                //case-1 (I don't refuel at current fuelstop)
                //If I didn't refuel at current stop, the max distance I can cover is equal to maximum
                //distance I could cover from previous state
                t[i][j] = t[i-1][j];
                
                //case-2 (I will refuel at current fuelStop)
                //But check if you can even reach this station (stations[i-1][0]) or not from your previous station
                if(t[i-1][j-1] >= stations[i-1][0]) {
                    t[i][j] = max(t[i][j], t[i-1][j-1] + stations[i-1][1]);
                }
                
            }
        }
        
        //After you end up with all stations, check which t[n][j] was best for reaching target
        //Best means, minimum j used by you to reach target
        for(int j = 0; j<n+1; j++) {
            if(t[n][j] >= target)
                return j;
        }
        
        //You could never reach target, so return -1
        return -1;
    }
};