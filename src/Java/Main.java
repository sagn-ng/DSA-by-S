class Dog {
    String name;
    Dog(String name) { this.name = name; }
}

public class Main {
    public static void changeName(Dog dog) {
        dog.name = "Gâu Gâu"; // Thao tác lên đối tượng mà 'dog' trỏ tới
    }
    public static void makeNew(Dog dog){
        dog=new Dog("Gâu Gâu");
    }

    public static void main(String[] args) {
        Dog myDog = new Dog("Cún");
        changeName(myDog);
        System.out.println(myDog.name); // Kết quả: "Gâu Gâu"

        myDog.name="Cún";
        makeNew(myDog);
        System.out.println(myDog.name); // Kết quả vẫn là "Cún"
    }
} //file java sẽ lấy tên của class được viết cuối cùng