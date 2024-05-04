public static List<Integer> findKthMinimumVulnerability(int k, int m, List<Integer> vulnerabilities) {
    int n = vulnerabilities.size();
    List<Integer> result = new ArrayList<>();

    PriorityQueue<Integer> minHeap = new PriorityQueue<>();
    for (int i = 0; i < m; i++) {
        minHeap.offer(vulnerabilities.get(i));
    }

    result.add(findKth(minHeap, k));

    for (int i = m; i < n; i++) {
        minHeap.remove(vulnerabilities.get(i - m));
        minHeap.offer(vulnerabilities.get(i));
        result.add(findKth(minHeap, k));
    }

    return result;
}

private static int findKth(PriorityQueue<Integer> minHeap, int k) {
    PriorityQueue<Integer> temp = new PriorityQueue<>(minHeap);
    for (int i = 0; i < k - 1; i++) {
        temp.poll();
    }
    return temp.peek();
}
