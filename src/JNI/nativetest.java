import java.io.IOException;

public class nativetest {
	public native int startSimulator(short paramCnt, String[] params);

	//never call this from java. It's been called from c++
	//c++ report action, take this action and return the observation tp c++
	public int reportAction(int action) {
		switch(action) {
		case 0 : return 1;
		case 1 : return 2;
		case 2 : return 0;
		default: return 0;
		}
	}
	
	static 
	{
		System.loadLibrary("native");
	}
	public static void main(String[] argv)
	{
//		final Runtime rt = Runtime.getRuntime();
//		try {
//			rt.exec("/home/zhengli/workspace2/appl-0.95/src/pomdpsim --simLen 10 --simNum 1 --policy-file ../out.policy /home/zhengli/workspace2/appl-0.95/examples/POMDP/DataCleaning1.pomdp");
//			System.out.println("Done");
//		} catch (IOException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
		nativetest nt = new nativetest();
		String[] params = {"simulate", "--simLen" ,"1000" ,"--simNum" ,"2" ,"--policy-file" ,"../out.policy" ,"../../examples/POMDP/DataCleaning1.pomdp"};
		int retval = nt.startSimulator((short)8, params);
		System.out.println("Returned Value: "+retval);
	}
}
