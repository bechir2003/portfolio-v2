#include "arduino2.h"

Arduino2::Arduino2()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString Arduino2::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduino2::getserial()
{
   return serial;
}
int Arduino2::connect_arduino()
{
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
           if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
               if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()
                       == arduino_uno_producy_id) {
                   arduino_is_available = true;
                   arduino_port_name=serial_port_info.portName();
               } } }
        qDebug() << "arduino_port_name is :" << arduino_port_name;
        if(arduino_is_available){
            serial->setPortName("COM6");
            if(serial->open(QSerialPort::ReadWrite)){
                serial->setBaudRate(QSerialPort::Baud9600);
                serial->setDataBits(QSerialPort::Data8);
                serial->setParity(QSerialPort::NoParity);
                serial->setStopBits(QSerialPort::OneStop);
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0;
            }
            return 1;
        }
        return -1;
}

int Arduino2::close_arduino()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;


}


 QByteArray Arduino2::read_from_arduino()
{
     QByteArray QByte;
    if(serial->isReadable()){
         data=serial->readAll();

         return data;
    }
    return QByte;
 }


int Arduino2::write_to_arduino( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);
        return 1;
    }else{
        qDebug() << "Couldn't write to serial!";
        return  0;
    }

}
