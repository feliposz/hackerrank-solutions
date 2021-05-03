

class SumInLeavesVisitor extends TreeVis {
    int sum = 0;
    
    public int getResult() {
        return sum;
    }

    public void visitNode(TreeNode node) {
    }

    public void visitLeaf(TreeLeaf leaf) {
      	sum += leaf.getValue();
    }
}

class ProductOfRedNodesVisitor extends TreeVis {
    long product = 1;
    final int M = 1000000007;
    
    public int getResult() {
        return (int)product;
    }

    public void visitNode(TreeNode node) {
      	if (node.getColor() == Color.RED) {
              product = (product * node.getValue()) % M;
        }
    }

    public void visitLeaf(TreeLeaf leaf) {
        if (leaf.getColor() == Color.RED) {
              product = (product * leaf.getValue()) % M;
        }
    }
}

class FancyVisitor extends TreeVis {
    long sum1 = 0;
    long sum2 = 0;
    public int getResult() {
        return (int)Math.abs(sum1 - sum2);
    }

    public void visitNode(TreeNode node) {
    	if ((node.getDepth() % 2) == 0) {
            sum1 += node.getValue();
        }
    }

    public void visitLeaf(TreeLeaf leaf) {
        if (leaf.getColor() == Color.GREEN) {
            sum2 += leaf.getValue();
        }
    }
}

public class Solution {

    static int[] values;
    static Color[] colors;
    static HashMap<Integer, HashSet<Integer>> edges;
  
    static void addEdge(int u, int v) {
        if (!edges.containsKey(u)) {
            edges.put(u, new HashSet<Integer>());
        }
        edges.get(u).add(v);
        if (!edges.containsKey(v)) {
            edges.put(v, new HashSet<Integer>());
        }
        edges.get(v).add(u);
    }
  
    public static Tree solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        values = new int[n+1];
        colors = new Color[n+1];
        edges = new HashMap<>(n+1);
        
        for (int i = 1; i <=n; i++) {
            values[i] = sc.nextInt();
        }
        
        for (int i = 1; i <=n; i++) {
            colors[i] = sc.nextInt() == 0 ? Color.RED : Color.GREEN;
        }
        
        if (n == 1) {
            return new TreeLeaf(values[1], colors[1], 0);
        }
        
        TreeNode root = new TreeNode(values[1], colors[1], 0);

        for (int i = 1; i < n; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            addEdge(u, v);
        }

        addChildren(root, 1);
        
        return root;
    }
    
    static void addChildren(TreeNode parentNode, int parent) {
        for (int i : edges.get(parent)) {
            edges.get(i).remove(parent);
            boolean hasChildren = edges.containsKey(i) && !edges.get(i).isEmpty();
            Tree node;
            if (hasChildren) {
                node = new TreeNode(values[i], colors[i], parentNode.getDepth() + 1);
            } else {
                node = new TreeLeaf(values[i], colors[i], parentNode.getDepth() + 1);
            }
            parentNode.addChild(node);
            if (hasChildren) {
                addChildren((TreeNode)node, i);
            }
        }
    }
    
    /*
    45136
56618427
14333
*/


