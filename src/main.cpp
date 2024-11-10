#include "lvgl.h"
#include "gui/gui.h"
#include "gui/app.h"
#include "Ticker.h"
#include "hardware/hardware.h"
#include "hardware/powermgm.h"

#if defined( NATIVE_64BIT )
    /**
     * for non arduino
     */                 
    void setup( void );
    void loop( void );

    int main( void ) {
        setup();
        while( 1 ) { loop(); };
        return( 0 );
    }
#endif // NATIVE_64BIT

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("Iniciando...");
    Serial.println("Iniciando...");
    Serial.printf("Heap libre: %d\n", ESP.getFreeHeap());
    Serial.printf("PSRAM libre: %d\n", ESP.getFreePsram());
    Serial.println("Configurando hardware...");
    hardware_setup();
    Serial.println("Hardware configurado");

    Serial.println("Configurando GUI...");
    gui_setup();
    Serial.println("GUI configurado");

    Serial.println("Llamando a funciones de configuración de aplicaciones...");
    app_autocall_all_setup_functions();
    Serial.println("Funciones de configuración de aplicaciones llamadas");

    Serial.println("Configuración post-hardware...");
    hardware_post_setup();
    Serial.println("Configuración post-hardware completada");

    Serial.println("Inicialización completa");
}

void loop(){
    powermgm_loop();
}
