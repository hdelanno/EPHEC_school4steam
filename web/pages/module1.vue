<script setup>
    let id = 0;

    const sensors = ref([
        {id: id++, mean: 20, units:"°C"},
        {id: id++, mean: 100, units:"kPa"},
        {id: id++, mean: 65, units:null},
    ]);
</script>

<template>
    <section>
      <p>This page will be displayed at the /module1 route.</p>
    </section>
    
    <div class="dashboard">
        <template v-for="sensor in sensors" :key="sensor.id">
            <Sensor :mean="sensor.mean" :units="sensor.units"/>
        </template>
        <Actuator name="Moteur 1"/>
        <Actuator name="Moteur 2"/>
    </div>
</template>


<style>
.dashboard {
    border-radius: 10px; 
    display: grid; 
    grid-template-columns: repeat(auto-fill, 100px); 
    grid-template-rows: repeat(auto-fill, 100px); 
    width: 100%; 
    gap: 5px;
}
</style>