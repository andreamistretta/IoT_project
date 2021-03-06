#include "HTTP.h"
#include <cstdio>

HTTP::HTTP() {
	http.setHost("http://192.168.1.52");
	if(testConnection())
		initLight();
}

HTTP::~HTTP() {
	//dtor
}

void HTTP::initLight() {
	request.setUri("/gpio/00");
	response = http.sendRequest(request);
	request.setUri("/gpio/10");
	response = http.sendRequest(request);
	request.setUri("/gpio/20");
	response = http.sendRequest(request);
}


void HTTP::turnOnLight(int idx) {
	if(testConnection()) {
		char buffer [10];
		request.setMethod(sf::Http::Request::Get);
		sprintf(buffer, "/gpio/%i1", idx);
		request.setUri(buffer);
		response = http.sendRequest(request);
	} else
		printf("Connection failed!\n");
}


void HTTP::turnOffLight(int idx) {
	if(testConnection()) {
		char buffer [10];
		request.setMethod(sf::Http::Request::Get);
		sprintf(buffer, "/gpio/%i0", idx);
		request.setUri(buffer);
		response = http.sendRequest(request);
	} else
		printf("Connection failed!\n");
}

bool HTTP::testConnection() {
	request.setUri("check/");
	//response = http.sendRequest(request);
	//if (response.getStatus() == sf::Http::Response::InvalidResponse)
	//	return false;
	//else
		return false;
}

