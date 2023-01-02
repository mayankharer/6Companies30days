// when the digits and position in both secret and guess are same then it is bulls
// if the other number match but have different positions then it is cow

// approach we create a bucket of 10 digits and manipulate the number of bulls and cows

class Solution {
    public String getHint(String secret, String guess) {
        if(secret.length() == 0) return "0A0B";

        int bull = 0,cow =0;
        int [] result = new int [10]; // create a bucket 

        for(int i=0;i<secret.length();i++){
            //at each iteration they check for one digit from secret and guess 

            int x = secret.charAt(i) - 48; //converting char to int in ascii terms 
            int y = guess.charAt(i) - 48;

            if(x == y) bull++; // if there is exact match between the two digits then we increment bull 
            else // condition for cow
            {
                // in case of secret key we [increment]++ add the value of result[i] th element in our bucket
                if(result[x] < 0){cow++;}
                result[x]++;

                // in case of guess key we [decrement]-- the value of result[i] th element in our bucket
                if(result[y] > 0){cow++;}
                result[y]--;
            }

        }
        return bull + "A" + cow + "B";
    }
}