class BoundedBlockingQueue {
    
    private Queue<Integer> q = new LinkedList<>();
    private int capacity;

    public BoundedBlockingQueue(int capacity) {
        this.capacity = capacity;
    }
    
    public void enqueue(int element) throws InterruptedException {
        while(q.size() == capacity) { Thread.yield(); }
        q.add(element);
    }
    
    public int dequeue() throws InterruptedException {
        while (q.size() == 0) { Thread.yield(); }
        return q.remove();
    }
    
    public int size() {
        return q.size();
    }
}
