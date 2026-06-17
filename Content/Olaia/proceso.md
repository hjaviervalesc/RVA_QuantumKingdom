# PASO 1: Implementación de Smooth Locomotion en VR (Unreal VR Template)

## Objetivo

Añadir movimiento continuo ("smooth locomotion") al VR Template de Unreal sin eliminar todavía el sistema de teleport original.

---

##  Cambios realizados

### 1. Creación de un VRPawn propio

Para evitar modificar directamente el VR Template original:

- Se realizó una copia del `VRPawn` del template.
- La copia se llama:

```
OlaiaVRPawn
```

A partir de ahora todas las modificaciones se realizan sobre este blueprint.

#### Motivo

Mantener intacto el VR Template original para:

- Evitar romper funcionalidades existentes.
- Poder comparar comportamientos.
- Tener una copia de seguridad funcional.

---

### 2. Cambio de GameMode

Se modificó el GameMode del proyecto para que utilice el nuevo Pawn.

---


### 3. Reorganización del Input Mapping Context (IMC)

#### Situación original

El VR Template utilizaba:

```
IA_Move
```

para controlar el teleport.

#### Cambio realizado

Se creó una nueva Input Action:

```
IA_SmoothMove
```

---

#### Nuevo esquema de controles

##### Joystick izquierdo

```
IA_SmoothMove
```

- X → Movimiento lateral (strafe)
- Y → Avance / retroceso

##### Joystick derecho

Se mantiene para:

- Snap Turn (eje X)

##### Teleport

Sigue asociado a:

```
IA_Move
```


---

### 5. Modificación del IMC

Dentro del Input Mapping Context:

Se añadió:

```
IA_SmoothMove
```
Con sus bindings correspondientes para el joystick izquierdo.
---


## Blueprint de Smooth Move

Se ha editado el blueprint para añadir el movimiento. La velocidad se puede cambiar con la variable MoveSpeed.
---


# PASO 2: Sistema básico de munición para la pistola

## Objetivo

Añadir un sistema de munición a la pistola del VR Template para controlar cuántas balas quedan disponibles y limitar el disparo cuando se agoten.

---

## Cambios realizados

### 1. Análisis del Blueprint de la pistola

Se decidió reutilizar el Blueprint de la pistola proporcionado por el VR Template. Se ha creado un child blueprint.

La lógica existente de disparo se mantiene intacta y se amplía con nuevas variables relacionadas con la munición.

---

### 2. Creación de variables de munición

Se añadieron dos variables de tipo Integer:

```
CurrentAmmo
```

Número de balas disponibles actualmente en el cargador.

Ejemplo:

```
15
```

---

```
MaxAmmo
```

Cantidad máxima de munición disponible para el arma.

Ejemplo:

```
100
```

---

### 3. Modificación de la lógica de disparo

Se localizó la función/evento responsable del disparo dentro del Blueprint de la pistola.

Antes de ejecutar el disparo se comprueba:

```
CurrentAmmo > 0
```

Si la condición es verdadera:

- Se realiza el disparo.
- Se reduce la munición actual en una unidad.

Si la condición es falsa:

- El arma no dispara.

---

### 4. Consumo de munición

Cada vez que se dispara:

```
CurrentAmmo = CurrentAmmo - 1
```

Esto permite llevar un control de las balas restantes en el cargador.

---

## Estado actual

El sistema permite:

- Definir la munición disponible.
- Reducir la munición al disparar.
- Impedir disparos cuando la munición llega a cero.

