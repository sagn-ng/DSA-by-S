package binary_tree;
import java.util.LinkedList;
public class LeftLeaves {
    /*a BFS solution*/
    public int sumOfLeftLeaves(TreeNode root){
        if (root==null) return 0;
        int sum=0;
        LinkedList<TreeNode> queue=new LinkedList<>();

        queue.add(root);
        while (!queue.isEmpty()){
            TreeNode u=queue.removeLast();
            if (u.left!=null){
                queue.add(u.left);
                if (u.left.left==null && u.left.right==null) sum+=u.left.val;
            }
            if (u.right!=null) queue.add(u.right);
        }
        return sum;
    }
}