#include "windows.h"
#include "rawdata/rawdata_video_source_helper_interface.h"
#include "ZoomSDKRendererDelegate.h"
#include "zoom_sdk_def.h" 
#include <iostream>
#include <cstdint>

#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;
using namespace ZOOM_SDK_NAMESPACE;


void ZoomSDKRendererDelegate::onRawDataFrameReceived(YUVRawDataI420* data)
{
	std::cout << "onRawDataFrameReceived." << endl;

	std::cout << "width." << data->GetStreamWidth() << endl;
	std::cout << "height." << data->GetStreamHeight() << endl;
	SaveToRawYUVFile(data);

}
void ZoomSDKRendererDelegate::onRawDataStatusChanged(RawDataStatus status)
{
	std::cout << "onRawDataStatusChanged." << endl;
}

void ZoomSDKRendererDelegate::onRendererBeDestroyed()
{
	std::cout << "onRendererBeDestroyed ." << endl;
}

//void ZoomSDKRendererDelegate::SaveToRawYUVFile(YUVRawDataI420* data) {
//
//	// Open the file for writing
//	ofstream outputFile("output.yuv", ios::out | ios::binary | ios::app);
//	if (!outputFile.is_open())
//	{
//		std::cout << "Error opening file." << endl;
//		return;
//	}
//
//	char* _data = new char[data->GetStreamHeight() * data->GetStreamWidth() * 3 / 2];
//
//	memset(_data, 0, data->GetStreamHeight() * data->GetStreamWidth() * 3 / 2);
//
//	// Copy Y buffer
//	memcpy(_data, data->GetYBuffer(), data->GetStreamHeight() * data->GetStreamWidth());
//
//	// Copy U buffer
//	size_t loc = data->GetStreamHeight() * data->GetStreamWidth();
//	memcpy(&_data[loc], data->GetUBuffer(), data->GetStreamHeight() * data->GetStreamWidth() / 4);
//
//
//	// Copy V buffer
//	loc = (data->GetStreamHeight() * data->GetStreamWidth()) + (data->GetStreamHeight() * data->GetStreamWidth() / 4);
//	memcpy(&_data[loc], data->GetVBuffer(), data->GetStreamHeight() * data->GetStreamWidth() / 4);
//
//
//
//	//outputFile.write((char*)data->GetBuffer(), data->GetBufferLen());
//	// Write the Y plane
//	outputFile.write(_data, data->GetStreamHeight() * data->GetStreamWidth() * 3 / 2);
//
//
//
//	// Close the file
//	outputFile.close();
//	outputFile.flush();
//	//std::cout << "YUV420 buffer saved to file." << endl;
//}
void ZoomSDKRendererDelegate::SaveToRawYUVFile(YUVRawDataI420* data) {

	// Open the file for writing
	ofstream outputFile("output.yuv", ios::out | ios::binary | ios::app);
	if (!outputFile.is_open())
	{
		std::cout << "Error opening file." << endl;
		return;
	}
	// Calculate the sizes for Y, U, and V components
	size_t ySize = data->GetStreamWidth() * data->GetStreamHeight();
	size_t uvSize = ySize / 4;

	// Write Y, U, and V components to the output file
	outputFile.write(data->GetYBuffer(), ySize);
	outputFile.write(data->GetUBuffer(), uvSize);
	outputFile.write(data->GetVBuffer(), uvSize);


	// Close the file
	outputFile.close();
	outputFile.flush();
	//std::cout << "YUV420 buffer saved to file." << endl;
}