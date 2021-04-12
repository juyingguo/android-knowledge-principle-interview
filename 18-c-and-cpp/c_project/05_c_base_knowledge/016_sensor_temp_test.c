#include <stdio.h>

#define MAX_NUM_SENSORS 5

#define SUPPORTED_SENSORS  ((1<<MAX_NUM_SENSORS)-1)

#define SENSORS_HANDLE_BASE             0 // copy from  aosp/hardware/libhardware/include/hardware/sensors.h

#define  ID_BASE           SENSORS_HANDLE_BASE
#define  ID_ACCELERATION   (ID_BASE+0)
#define  ID_MAGNETIC_FIELD (ID_BASE+1)
#define  ID_ORIENTATION    (ID_BASE+2)
#define  ID_TEMPERATURE    (ID_BASE+3)
#define  ID_MY_ADD_SENDOR    (ID_BASE+4) // my test add type by date:2020/03/26.

#define  SENSORS_ACCELERATION   (1 << ID_ACCELERATION)
#define  SENSORS_MAGNETIC_FIELD  (1 << ID_MAGNETIC_FIELD)
#define  SENSORS_ORIENTATION     (1 << ID_ORIENTATION)
#define  SENSORS_TEMPERATURE     (1 << ID_TEMPERATURE)


#define  ID_CHECK(x)  ((unsigned)((x)-ID_BASE) < 4)

//#define  SENSORS_LIST  SENSOR_(ACCELERATION,"acceleration") SENSOR_(MAGNETIC_FIELD,"magnetic-field")  SENSOR_(ORIENTATION,"orientation") SENSOR_(TEMPERATURE,"temperature") SENSOR_(MY_ADD_SENDOR,"my_add_sensor") \

#define  SENSORS_LIST  \
	SENSOR_(ACCELERATION,"acceleration") \
	SENSOR_(MAGNETIC_FIELD,"magnetic-field")  \
	SENSOR_(ORIENTATION,"orientation") \
	SENSOR_(TEMPERATURE,"temperature") \
	SENSOR_(MY_ADD_SENDOR,"my_add_sensor") 
static const struct {
    const char*  name;
    int          id; } _sensorIds[MAX_NUM_SENSORS] =
{
#define SENSOR_(x,y)  { y, ID_##x },
    SENSORS_LIST
#undef  SENSOR_
};


static const char*
_sensorIdToName( int  id )
{
    int  nn;
    for (nn = 0; nn < MAX_NUM_SENSORS; nn++)
        if (id == _sensorIds[nn].id)
            return _sensorIds[nn].name;
    return "<UNKNOWN>";
}

static int
_sensorIdFromName( const char*  name )
{
    int  nn;

    if (name == NULL)
        return -1;

    for (nn = 0; nn < MAX_NUM_SENSORS; nn++)
        if (!strcmp(name, _sensorIds[nn].name))
            return _sensorIds[nn].id;

    return -1;
}
int main(void)
{
	
   printf("ID_CHECK(5): %d \n",ID_CHECK(5));
   
   const char *curr_name = _sensorIdToName(4);
   int curr_id = _sensorIdFromName("temperature");
   printf("curr_name =  %s \n",curr_name);
   printf("curr_id =  %d \n",curr_id);
   
   return 0;
}
