using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class setPosition : MonoBehaviour {


	public GameObject positionTracker;
	public GameObject drone;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		//Debug.Log ("nokta position"+transform.position);

		transform.position = positionTracker.transform.position;

		//Debug.Log("Position tracker"+positionTracker.transform.position);

	


	
	}
}
