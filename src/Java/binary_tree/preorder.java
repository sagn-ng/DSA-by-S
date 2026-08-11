package binary_tree;
import java.util.ArrayList;
import java.util.List;
public class preorder {
    public static List<Integer> preorderTraversal(TreeNode root){
        TreeNode prev=null, cur=root;

        List<Integer> result=new ArrayList<>();
        if (root==null) return result;
        List<TreeNode> stack=new ArrayList<>();
        int last=-1;
        while (cur!=null || last!=-1){
            while (cur!=null){
                result.add(cur.val);
                stack.add(cur);
                cur=cur.left;
                last++;
            } //"cur" is now null

            prev=stack.remove(last--);
            cur=prev.right;
            /*these 2 lines mean we're moving to the right,
            we have done a "root -> left -> right, so we can remove the "root",
            which is the top of the stack*/
        }
        return result;
    }
}
//the recursive solution is quite trivial, so i don't do it here