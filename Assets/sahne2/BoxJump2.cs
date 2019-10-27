using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoxJump2 : MonoBehaviour {


	public GameObject radar;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {

	
	

		if (Input.GetKeyDown (KeyCode.Space)) {


			GetComponent<ParabolaController2> ().FollowParabola ();
			GetComponent<Animator> ().enabled = false;
			GetComponent<Animation> ().enabled = false;



			radar.SetActive (false);


		}
	}
}
