class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        boolean[] v = new boolean[rooms.size()];
        v[0] = true;
        Stack<Integer> s = new Stack<>();
        s.push(0);
        int c = 1;
        
        while (!s.isEmpty()) {
            for (int k : rooms.get(s.pop())) {
                if (!v[k]) {
                    v[k] = true;
                    s.push(k);
                    c++;
                }
            }
        }
        return c == rooms.size();
    }
}