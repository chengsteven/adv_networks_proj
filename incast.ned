//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//


import ned.IBidirectionalChannel;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.inet.StandardHost;
import inet.node.inet.Router;
import inet.node.ethernet.EtherSwitch;
import inet.node.ethernet.Eth1G;



//simple sender_node
//{
//    gates:
//        output out;
//        input in;
//}
//
//simple receiver_node
//{
//    gates:
//        input in1;
//        input in2;
//        input in3;
//        input in4;
//        output out1;
//        output out2;
//        output out3;
//        output out4;
//}

//network incast
//{
//    submodules:
//        sender_node1: sender_node {
//            @display("p=51,49");
//        }
//        sender_node2: sender_node {
//            @display("p=146,49");
//        }
//        sender_node3: sender_node {
//            @display("p=237,49");
//        }
//        sender_node4: sender_node {
//            @display("p=330,49");
//        }
//        receiver_node1: receiver_node {
//            @display("p=185,157");
//        }
//    connections:
//        sender_node1.out --> { delay = 300ms; } --> receiver_node1.in1;
//        sender_node2.out --> { delay = 300ms; } --> receiver_node1.in2;
//        sender_node3.out --> { delay = 300ms; } --> receiver_node1.in3;
//        sender_node4.out --> { delay = 300ms; } --> receiver_node1.in4;
//        receiver_node1.out1 --> { delay = 300ms; } --> sender_node1.in;
//        receiver_node1.out2 --> { delay = 300ms; } --> sender_node2.in;
//        receiver_node1.out3 --> { delay = 300ms; } --> sender_node3.in;
//        receiver_node1.out4 --> { delay = 300ms; } --> sender_node4.in;
//        
//
//}

network WiredNetworkExample
{
    parameters:
        int numClients; // number of clients in the network
    submodules:
        configurator: Ipv4NetworkConfigurator; // network autoconfiguration
        server: StandardHost; // predefined standard host
        router: Router; // predefined router
        switch: EtherSwitch; // predefined ethernet switch
        client[numClients]: StandardHost;
    connections: // network level connections
        router.pppg++ <--> { datarate = 1GBps; } <--> server.pppg++; // PPP
        switch.ethg++ <--> Eth1G <--> router.ethg++; // bidirectional ethernet
        for i=0..numClients-1 {
            client[i].ethg++ <--> Eth1G <--> switch.ethg++; // ethernet
        }
}

