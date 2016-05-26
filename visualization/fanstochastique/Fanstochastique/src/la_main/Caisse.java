package la_main;

import java.util.ArrayList;

public class Caisse {
	
	private String name;
	private String status;
	private String v_moy;
	private String v_max;
	private int client_total;
	private String happy_client;
	private String unhappy_client;
	private String neutral_client;
	private ArrayList<ArrayList<String>> clients;
	
	public Caisse (String name, String status, String v_moy, String v_max, String client_total, String happy_client, String unhappy_client, ArrayList<ArrayList<String>> clients) {
		
		this.name = name;
		this.status = status;
		this.v_moy = v_moy;
		this.v_max = v_max;
		this.client_total = Integer.parseInt(client_total);
		this.happy_client = happy_client;
		this.unhappy_client = unhappy_client;
		this.neutral_client = String.valueOf(Integer.parseInt(client_total) - Integer.parseInt(happy_client) - Integer.parseInt(unhappy_client));
		this.clients= clients;
	}

	public ArrayList<ArrayList<String>> getClients() {
		return clients;
	}

	public String getName() {
		return name;
	}

	public String getStatus() {
		return status;
	}

	public String getV_moy() {
		return v_moy;
	}

	public String getV_max() {
		return v_max;
	}

	public int getClient_total() {
		return client_total;
	}

	public String getHappy_client() {
		return happy_client;
	}

	public String getUnhappy_client() {
		return unhappy_client;
	}
	
	
}
