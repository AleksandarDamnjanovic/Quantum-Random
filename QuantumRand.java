/*
 * Title: Quantum Random
 * Author: Aleksandar Damnjanovic
 * Date: 21.11.2021
 */

import java.io.IOException;
import java.math.BigInteger;
import java.net.URL;
import java.util.Scanner;
import org.json.JSONArray;
import org.json.JSONObject;

public class QuantumRand {
	
	private long value=-1;
	private String address="https://qrng.anu.edu.au/API/jsonI.php?length=1&type=hex16&size=8";
	
	public QuantumRand() {
		next();
	}
	
	public long getLong() {
		return value;
	}
	
	public long next() {
		try {
			URL url= new URL(address);
			Scanner scan= new Scanner(url.openStream());
			String content = scan.next();
			
			JSONObject obj= new JSONObject(content);
			JSONArray array= (JSONArray) obj.get("data");
			String num= array.get(0).toString();
			BigInteger bi = new BigInteger(num, 16);
			long val= bi.longValue();
			value= Math.abs(val);
			return value;
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return -1;
	}
	
	public long getLong(long min, long max) {
		if(min<0 || max>Long.MAX_VALUE) {
			System.out.println("min must be bigger than 0\nmax must be less that "+Long.MAX_VALUE);
			return -1;
		}
		
		long ret=0;
		if(max!= Long.MAX_VALUE)
			if(this.value> max)
				ret= this.value %max;
		
		if(ret<min && ret!=0)
			ret= min + (this.value % (max-min));
		
		return ret;
	}
	
	public double getFloat() {
		double ret=0;
		if(this.value<Long.MAX_VALUE)
			ret= (double)(this.value) / (double)(Long.MAX_VALUE);
		else
			ret=(double)(Long.MAX_VALUE) / (double)(this.value);
		
		return ret;
	}
	
}