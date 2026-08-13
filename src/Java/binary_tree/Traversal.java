package binary_tree;

import java.util.ArrayList;
import java.util.List;

public class Traversal {
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

class TraversalTest{
    public static void main(String[] args) {
        TreeNode root=new TreeNode(12);
        root=new TreeNode(11, root, null);
        root=new TreeNode(10, root, null);

        root.right=new TreeNode(13);

        root=new TreeNode(3, null, root);

        root=new TreeNode(2, root, null);
        root.right=new TreeNode(4, null, new TreeNode(5));

        root=new TreeNode(1, root, null);

        TreeNode u=new TreeNode(6, new TreeNode(7), new TreeNode(9));
        root.right=u;


        List<Integer> inorder=Traversal.inorderTraversal(root);
        System.out.println(inorder);

        List<Integer> pre=Traversal.preorderTraversal(root);
        System.out.println(pre);
        
        List<Integer> post=Traversal.postorderTraversal(root);
        System.out.println(post);
    }
}