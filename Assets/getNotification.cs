using UnityEngine;
using System.Collections;
using UnityEngine.Networking;
using System.Collections.Generic;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using UnityEngine.UI;



public class getNotification: MonoBehaviour {
	MyClass myObject = new MyClass();
	string[] messages;
	Text guiText;
	int message_counter=1,maxlength=0;
	void increase_message_counter(){
		//Debug.Log (messages);


		string message = messages [message_counter];
		if (message [0] != '{') {
			message = "{" + message;
			}

		if (message [message.Length-1] != '}') {
			message =  message+"}";
		}




		myObject=JsonUtility.FromJson<MyClass>(message);


		guiText.text = myObject.messageBody;




		if (message_counter < maxlength-1) {
			
			message_counter += 1;
		} else {
			message_counter = 0;

		}
	}





	void Start()
	{
		guiText=GameObject.Find("notification").GetComponent<Text>(); 

		// A correct website page.
		StartCoroutine(GetRequest("https://api.nasa.gov/DONKI/notifications?type=all&api_key=bwJxSYu1hZDEpW5rVVzw9CMrCLJqgtvbR4EoXqON"));

		// A non-existing page.

	InvokeRepeating ("increase_message_counter", 0,10);

	}

	IEnumerator GetRequest(string uri)
	{
		using (UnityWebRequest webRequest = UnityWebRequest.Get(uri))
		{
			// Request and wait for the desired page.
			yield return webRequest.Send();

			string[] pages = uri.Split('/');
			int page = pages.Length - 1;

		

			string response = webRequest.downloadHandler.text;
			//"[,]" kesilecek


			response = response.Substring (1,response.Length-2);


			string[] stringSeparators = new string[] {"},{"};


			messages=response.Split (stringSeparators,System.StringSplitOptions.None);
		//	Debug.Log ( response.Substring (response.Length-20,20));
			//Debug.Log (response[response.Length-1]);
			maxlength=messages.Length;

			//JSONObject j = new JSONObject(response);
	
			//Debug.Log (messages [0]);
			string message = messages [0]+"}";

		//	Debug.Log (message);

		//if (message [0] != '{') {
			//	message = "{" + message;
		//	}
			myObject=JsonUtility.FromJson<MyClass>(message);


			guiText.text = myObject.messageBody;
		


		

	

	//	MyClass myObject = new MyClass();
		


	//		myObject=JsonUtility.FromJson<MyClass>(message);

			//Debug.Log (myObject.messageType+myObject.messageBody);

		


			/*

				Debug.Log (d.Key);

			}

		*/




	//		Dictionary<string, string> speedDebuffs = new Dictionary<string, string> ();


		//	foreach (	Dictionary<string, string> data  in j.list) {

		//		Debug.Log (data);
//}



		}
	}



}


[System.Serializable]
public class MyClass
{


	public string messageBody;
	public string messageType;
}
