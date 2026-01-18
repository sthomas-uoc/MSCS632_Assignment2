import java.util.*;

public class MemoryJava {

  private static List<String> dataGen(int count) {
    List<String> data = new ArrayList<>(count);

    for(int i=0; i<count; i++) {
      data.add("" + i * 2);
    }
    
    return data;
  }

  public static void workData() throws Exception {
    
    List<String> data = dataGen(1000000);

    System.out.println("Data ready");
    System.in.read();

    System.out.println("Size: " + data.size());


  }

  public static void main(String[] args) throws Exception {

    System.out.println("Application starting");
    
    // Attempt to force GC
    System.gc();
    
    System.out.println("Press any key to setup large memory use");
    System.in.read();

    workData();

    System.out.println("Press any key to attempt to run GC");
    System.in.read();
    // Attempt to force GC
    System.gc();

    System.out.println("Press any key to exit");
    System.in.read();
    
    return;
  }
}



