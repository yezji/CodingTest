
class Main {
    public static void main(String[] args) {
        String answer = "";
        Integer n=3;
        Character c[] = {'수', '박'};
        for(int i=0; i<n; i++) {
            if(i%2 == 0) answer+=c[0];
            else answer+=c[1];
        }
        System.out.println(answer);
    }
}