using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
public class BoxJump : MonoBehaviour {

	public GameObject scrollArea;
	public GameObject tutorial;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {

	
	

		if (Input.GetKeyDown (KeyCode.Space)) {


			GetComponent<ParabolaController> ().FollowParabola ();
			scrollArea.SetActive (false);
			tutorial.SetActive (false);

		}


		else if(Input.GetKeyDown (KeyCode.F9)){

			//Debug.Log ("f9 deneme");

			SceneManager.LoadScene ("sahne2");
	}
}
}