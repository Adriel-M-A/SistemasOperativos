#include <linux/module.h> /* Lib para modulos */
#include <linux/kernel.h> /* Para usar la macro KERN_INFO */
#include <linux/init.h> /* Para usar la macro de inicio y fin */

/*
10.Implemente un pequeño ejemplo de un módulo funcional en lenguaje C, indicando
los pasos necesarios para su creación. El módulo puede ser algo tan sencillo como
mostrar un mensaje al cargarlo y otro al descargarlo.
*/

static init __init_mi_modulostart(void){
    printk(KERN_INFO "hola mundo");
}

static exit __exit_mi_moduloexit(void){
    printk(KERN_INFO "chau mundo");
}

