import java.io.IOException;
import java.util.Random;

public class nativetest {
	public native int startSimulator(short paramCnt, String[] params);
	
	private Random r = new Random();
	//never call this from java. It's been called from c++
	//c++ report action, take this action and return the observation to the simulator in c++
	public int reportAction(int action) {
		//return observation after taking this action
		int obs = Math.abs( (r.nextInt() + action) % 29 );
		return obs;
	}
	
	static 
	{
		System.loadLibrary("native");
	}
	public static void main(String[] argv)
	{
		nativetest nt = new nativetest();
		nt.r.setSeed(System.currentTimeMillis());
		//The following line is the parameters to send to the simulator
		//Generate policy file before using this program. You can generate policy file out.policy using pomdpsol
		//Also, you need to specify the model file e.g. ../../examples/POMDP/TagAvoid.pomdp
		String[] params = {"simulate", "--simLen" ,"3" ,"--simNum" ,"100" ,"--policy-file" ,"../out.policy" ,"../../examples/POMDP/TagAvoid.pomdp"};
		int retval = nt.startSimulator((short)8, params);
		System.out.println("Returned Value: "+retval);
	}
}
