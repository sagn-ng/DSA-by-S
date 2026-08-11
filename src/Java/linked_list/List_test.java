package linked_list;

public class List_test {
    public static void main(String[] args) {
        ListNode node=new ListNode(1, new ListNode(2));
        ListNode test1=node, test2=node;
        test1.next=null;
        System.out.println((test2.next==null));
    }
}
