package binary_tree;
import java.util.List;
import java.util.ArrayList;
public class postorder {
    public static List<Integer> postorderTraversal(TreeNode root){
        List<Integer> result=new ArrayList<>();
        if (root==null) return result;
        
        List<TreeNode> stack=new ArrayList<>();
        TreeNode lastRemove=null;
        TreeNode cur=root; int last=-1;
        while (cur!=null || last!=-1){
            while (cur!=null){
                stack.add(cur);
                last++;
                cur=cur.left;
            }

            TreeNode peekNode=stack.get(last);
            if (peekNode.right!=null && peekNode.right!=lastRemove){
                cur=peekNode.right;
            }
            else {
                result.add(peekNode.val);
                lastRemove=stack.remove(last--);
            }
        }
        return result;
    }
}