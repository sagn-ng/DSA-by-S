package binary_tree;
import java.util.ArrayList;
import java.util.List;

public class inorder {
    public static List<Integer> inorderTraversal(TreeNode root) {
        List<TreeNode> stack=new ArrayList<>();
        int last=-1;

        List<Integer> result=new ArrayList<>();
        TreeNode cur=root;
        while (cur!=null || !stack.isEmpty()){
            while (cur!=null){
                last++;
                stack.add(cur);
                cur=cur.left;
            }

            cur=stack.remove(last);
            last--;
            result.add(cur.val);
            cur=cur.right;
        }
        return result;
    }
}