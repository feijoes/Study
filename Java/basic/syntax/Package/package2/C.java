package package2;
import package1.*;
public class C {

    public String publicMessage = "public message";
    protected String protectedMessage = "protected message";
    private String privateMessage = "private message";
    String Message = "This is defaul";
}
// Nothing, make unreachable in others package
// public make global in all package (world)
// protected make unreachable in others package thats not is a subclass
// private, local varible/class/function
