import java.util.LinkedList;

class Truck {
    Integer weight;
    Integer move;

    public Truck(Integer weight) {
        this.weight = weight;
        this.move = 0;
    }
}

class Main {
    public static void main(String[] args) {
        Integer bridge_length = 2;
        Integer weight = 10;
        Integer truck_weights[] = {7,4,5,6};
//        Integer bridge_length = 100;
//        Integer weight = 100;
//        Integer truck_weights[] = {10,10,10,10,10,10,10,10,10,10};
        LinkedList<Truck> q = new LinkedList<Truck>();
        Integer tidx = 0;
        Integer tsum = 0;
        Integer time = 0;

        while(true) {
            if(!q.isEmpty()) {
                for(int i=0; i<q.size(); i++) {
                    q.get(i).move++;
                }
            }
            if(!q.isEmpty() && q.peek().move>=bridge_length) {
                tsum-=q.pop().weight;
            }
            if(tidx < truck_weights.length && tsum+truck_weights[tidx] <= weight) {
                Truck t = new Truck(truck_weights[tidx]);
                q.add(t);
                tsum+=truck_weights[tidx++];
            }
            time++;
            if(q.isEmpty() && tidx>=truck_weights.length-1 && tsum==0) break;
        }

        System.out.println(time);
    }
}