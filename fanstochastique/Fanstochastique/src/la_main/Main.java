package la_main;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;

import javax.swing.JFileChooser;

import org.json.JSONArray;
import org.json.JSONObject;
import org.json.simple.parser.JSONParser;

public class Main {
	

	public static void main(String[] args) {

		
        ArrayList<ArrayList<Caisse>> data_AL = new ArrayList<ArrayList<Caisse>>();

        data_AL = importTheJSON();
		
        
	}
	
	public static String readFile(String path, Charset encoding) throws IOException 
			{
			  byte[] encoded = Files.readAllBytes(Paths.get(path));
			  return new String(encoded, encoding);
			}
	
	
	public static ArrayList<ArrayList<Caisse>> importTheJSON(){
		
        JSONParser parser = new JSONParser();
        
        JSONArray jsonDataArray;
        JSONArray jsonCaisseArray;
        JSONArray jsonClientsArray;
        
        ArrayList<ArrayList<Caisse>> data_AL = new ArrayList<ArrayList<Caisse>>();
        ArrayList<Caisse> ti_AL = new ArrayList<Caisse>(); // ti_AL contient le string temps et un objet Caisse
        ArrayList<ArrayList<String>> clients_AL = new ArrayList<ArrayList<String>>();
        ArrayList<String> clientSeul_AL = new ArrayList<String>();

        
        String name;
        String status;
        String v_moy;
        String v_max;
        String client_total;
        String happy_client;
        String unhappy_client;
        String statusClient;
        String theta_s;
        
        try {
 
            
            String content = readFile("format.json", StandardCharsets.UTF_8);
            
            JSONObject jsonRootObject = new JSONObject(content);

            jsonDataArray = jsonRootObject.optJSONArray("data");
            
            for (int i = 0; i < jsonDataArray.length(); i++) { // Pour tous les temps ti
            	
            	JSONObject time_JSONobj = jsonDataArray.getJSONObject(i); // On sélectionne le jsonobject temps ti
            	
            	ti_AL = new ArrayList<Caisse>();
            	
            	jsonCaisseArray = time_JSONobj.optJSONArray("caisses"); // L'array de json objects caisses
            	
            	for (int j = 0; j < jsonCaisseArray.length(); j++){ // pour chaque caisse j
            		JSONObject caisse_JSONobj = jsonCaisseArray.getJSONObject(j);
            		
            		            		
            		name = caisse_JSONobj.optString("name");
            		status = caisse_JSONobj.optString("status");
            		v_moy = caisse_JSONobj.optString("v_moy");
            		v_max = caisse_JSONobj.optString("v_max");
            		client_total = caisse_JSONobj.optString("client_total");
            		happy_client = caisse_JSONobj.optString("happy_client");
            		unhappy_client = caisse_JSONobj.optString("unhappy_client");
            		//System.out.println(client_total);
            		jsonClientsArray = caisse_JSONobj.optJSONArray("clients"); // L'array de json objects clients

            		clients_AL = new ArrayList<ArrayList<String>>();
            		
            		for (int k = 0; k < jsonClientsArray.length(); k++){ // pour chaque client k
            			JSONObject client_JSONobj = jsonClientsArray.getJSONObject(k);

            			clientSeul_AL = new ArrayList<String>();
            			
            			statusClient = client_JSONobj.optString("status");
            			theta_s = client_JSONobj.optString("theta_s");
            			clientSeul_AL.add(statusClient);
            			clientSeul_AL.add(theta_s);
            			
            			clients_AL.add(clientSeul_AL);
            			
            		}
            		
            		ti_AL.add(new Caisse(name,status,v_moy,v_max,client_total, happy_client, unhappy_client,clients_AL));
            		
            		
            	}
            	
            	data_AL.add(ti_AL);
            
            }
            
            //System.out.println(data_AL.get(0).get(1).getClients().get(2).get(0));
 

        } catch (Exception e) {
            e.printStackTrace();
        }
        return data_AL;
	}
}