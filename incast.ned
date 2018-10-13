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


simple sender_node
{
    gates:
        output out;
}

simple receiver_node
{
    gates:
        input in1;
//        input in2;
//        input in3;
//        input in4;
}

network incast
{
    submodules:
        sender_node1: sender_node {
            @display("p=51,49");
        }
//        sender_node2: sender_node {
//            @display("p=146,49");
//        }
//        sender_node3: sender_node {
//            @display("p=237,49");
//        }
//        sender_node4: sender_node {
//            @display("p=330,49");
//        }
        receiver_node1: receiver_node {
            @display("p=185,157");
        }
    connections:
        sender_node1.out --> {  delay = 3000ms; } --> receiver_node1.in1;
//        sender_node2.out --> {  delay = 1ms; } --> receiver_node1.in2;
//        sender_node3.out --> {  delay = 1ms; } --> receiver_node1.in3;
//        sender_node4.out --> {  delay = 1ms; } --> receiver_node1.in4;

}
