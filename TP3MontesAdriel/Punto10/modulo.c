// Definiendo __KERNEL__ and MODULE nos permite acceder a nivel de kernel.
//root@pc#undef __KERNEL__
//root@pc#define __KERNEL__
//root@pc#undef MODULE
//root@pc#define MODULE

#include <linux/module.h> /* Lib para modulos */
#include <linux/kernel.h> /* Para usar la macro KERN_INFO */
#include <linux/init.h> /* Para usar la macro de __init y __exit */

/*
10.Implemente un pequeño ejemplo de un módulo funcional en lenguaje C, indicando
los pasos necesarios para su creación. El módulo puede ser algo tan sencillo como
mostrar un mensaje al cargarlo y otro al descargarlo.
*/

static int __init mi_modulostart(void){
    printk(KERN_INFO "hola mundo");
    return 0;
}

static void __exit mi_moduloexit(void){
    printk(KERN_INFO "chau mundo");
}

module_init(mi_modulostart);
module_exit(mi_moduloexit);
