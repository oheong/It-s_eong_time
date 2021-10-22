class Solution {
    static public long gcd(long w, long h){
        long min = 0;
        long max = 0;
        
        if(w < h) min = w;
        else min = h;
        
        for(long i = 1; i <= min; i++){
            if(w % i == 0 && h % i == 0){
                if(max < i) max = i;
            }
        }
        return max;
    }
    public long solution(int w, int h) {
        
        //W*H의 사각형을 대각선으로 잘랐을때 망가지게되는 사각형을 구하는 최종 공식 : [ W+H-최대공약수 ]
        // MICHIN 이런 생각 어떻게하지,,?
        
        long ww = Long.parseLong(String.valueOf(w));
        long hh = Long.parseLong(String.valueOf(h));
        
        return (ww * hh) - (ww + hh - gcd(ww,hh));
    }
}
