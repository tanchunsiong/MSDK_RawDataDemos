#pragma once
#include "windows.h"
#include "rawdata/rawdata_video_source_helper_interface.h"
#include "rawdata/rawdata_renderer_interface.h"
#include "zoom_sdk.h"
#include "zoom_sdk_raw_data_def.h"

#include <iostream>
#include <cstdint>

using namespace std;
using namespace ZOOMSDK;

class VideoSource :
	public IZoomSDKRendererDelegate
{
public:
	virtual void onRawDataFrameReceived(YUVRawDataI420* data);
	virtual void onRawDataStatusChanged(RawDataStatus	status);

	virtual void onRendererBeDestroyed();

};