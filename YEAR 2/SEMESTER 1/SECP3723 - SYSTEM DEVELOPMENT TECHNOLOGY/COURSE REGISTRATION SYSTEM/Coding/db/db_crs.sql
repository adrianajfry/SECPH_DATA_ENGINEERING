-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3307
-- Generation Time: Jan 31, 2025 at 03:56 PM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `db_crs`
--

-- --------------------------------------------------------

--
-- Table structure for table `tb_course`
--

CREATE TABLE `tb_course` (
  `c_code` varchar(10) NOT NULL,
  `c_name` varchar(50) NOT NULL,
  `c_credit` int(11) NOT NULL,
  `c_lec` varchar(10) NOT NULL,
  `c_sem` enum('2024/2025-1','2024/2025-2') NOT NULL,
  `c_max` int(30) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tb_course`
--

INSERT INTO `tb_course` (`c_code`, `c_name`, `c_credit`, `c_lec`, `c_sem`, `c_max`) VALUES
('SECD3761', 'Technopreneurship Seminar', 1, 'L004', '2024/2025-2', 5),
('SECJ2013', 'Data Structure and Algorithm', 3, 'L003', '2024/2025-1', 5),
('SECJ2154', 'Object Oriented Programming', 4, 'L003', '2024/2025-2', 5),
('SECP2523', 'Database (WBL)', 3, 'L004', '2024/2025-1', 5),
('SECP2753', 'Data Mining', 3, 'L004', '2024/2025-2', 5),
('SECP3204', 'Software Engineering (WBL)', 4, 'L003', '2024/2025-1', 5),
('SECP3223', 'Data Analytics Programming', 3, 'L003', '2024/2025-2', 5),
('SECP3723', 'System Development Technology', 3, 'L004', '2024/2025-1', 5),
('SECR1213', 'Network Communications', 3, 'L003', '2024/2025-1', 5),
('SECR2043', 'Operating Systems', 3, 'L004', '2024/2025-2', 5),
('UHLB2122', 'Professional Communication Skills', 2, 'L003', '2024/2025-2', 5),
('ULRS1022', 'Philosophy & Current Issues', 2, 'L004', '2024/2025-2', 5);

-- --------------------------------------------------------

--
-- Table structure for table `tb_registration`
--

CREATE TABLE `tb_registration` (
  `r_tid` int(11) NOT NULL,
  `r_student` varchar(11) NOT NULL,
  `r_course` varchar(10) NOT NULL,
  `r_sem` enum('2024/2025-1','2024/2025-2') NOT NULL,
  `r_status` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tb_registration`
--

INSERT INTO `tb_registration` (`r_tid`, `r_student`, `r_course`, `r_sem`, `r_status`) VALUES
(3, 'S005', 'SECJ2013', '2024/2025-1', 1),
(4, 'S005', 'SECP2523', '2024/2025-1', 1),
(5, 'S005', 'SECP3204', '2024/2025-1', 1),
(6, 'S005', 'SECP3723', '2024/2025-1', 1),
(7, 'S005', 'SECR1213', '2024/2025-1', 1),
(8, 'S006', 'SECJ2013', '2024/2025-1', 1),
(9, 'S006', 'SECP2523', '2024/2025-1', 1),
(10, 'S006', 'SECP3204', '2024/2025-1', 1),
(11, 'S006', 'SECP3723', '2024/2025-1', 1),
(15, 'S001', 'SECP2523', '2024/2025-1', 2),
(16, 'S001', 'SECP3204', '2024/2025-1', 2),
(17, 'S001', 'SECP3723', '2024/2025-1', 2),
(18, 'S001', 'SECR1213', '2024/2025-1', 2),
(19, 'S001', 'SECJ2013', '2024/2025-1', 2),
(20, 'S001', 'SECD3761', '2024/2025-2', 2),
(21, 'S001', 'SECJ2154', '2024/2025-2', 2),
(22, 'S001', 'SECP2753', '2024/2025-2', 2),
(23, 'S001', 'SECP3223', '2024/2025-2', 2),
(24, 'S001', 'SECR2043', '2024/2025-2', 2),
(25, 'S001', 'UHLB2122', '2024/2025-2', 2),
(26, 'S001', 'ULRS1022', '2024/2025-2', 2),
(27, 'S003', 'SECJ2013', '2024/2025-1', 2),
(28, 'S003', 'SECP2523', '2024/2025-1', 2),
(29, 'S003', 'SECP3204', '2024/2025-1', 2),
(30, 'S003', 'SECP3723', '2024/2025-1', 2),
(31, 'S003', 'SECR1213', '2024/2025-1', 2),
(32, 'S004', 'SECJ2013', '2024/2025-1', 2),
(33, 'S004', 'SECP2523', '2024/2025-1', 2),
(34, 'S004', 'SECR1213', '2024/2025-1', 2),
(35, 'S007', 'SECR1213', '2024/2025-1', 2),
(36, 'S003', 'SECP3223', '2024/2025-2', 2);

-- --------------------------------------------------------

--
-- Table structure for table `tb_status`
--

CREATE TABLE `tb_status` (
  `s_id` int(11) NOT NULL,
  `s_desc` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tb_status`
--

INSERT INTO `tb_status` (`s_id`, `s_desc`) VALUES
(1, 'Received'),
(2, 'Accepted'),
(3, 'Rejected');

-- --------------------------------------------------------

--
-- Table structure for table `tb_user`
--

CREATE TABLE `tb_user` (
  `u_sno` varchar(11) NOT NULL,
  `u_pwd` varchar(255) NOT NULL,
  `u_email` varchar(255) NOT NULL,
  `u_name` varchar(100) NOT NULL,
  `u_contact` int(11) NOT NULL,
  `u_state` varchar(100) NOT NULL,
  `u_reg` date NOT NULL,
  `u_utype` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tb_user`
--

INSERT INTO `tb_user` (`u_sno`, `u_pwd`, `u_email`, `u_name`, `u_contact`, `u_state`, `u_reg`, `u_utype`) VALUES
('A001', '$2y$10$V3ShEhpu.VOSJva0r0z05O4Hfcuz7WgWtGnDIg6Gusmu1Og777ALe', 'arian.lee@gmail.com', 'Arian Lee', 154443322, 'Selangor', '2025-01-31', 3),
('A002', '$2y$10$3/uj/d7nW1rB2u8.t.ffw.WwGOE/d00CiPMbHn1FEBxGGWjy6YcJG', 'dhea.arya@gmail.com', 'Dhea Arya', 196667777, 'Perak', '2025-01-31', 3),
('L003', '$2y$10$Y2m6ct/AoU8T06yaYkeQIOVUPm4lFib9yw.7snbl/ffLPfoOlDEAC', 'beatrice.rini@gmail.com', 'Beatrice Rini', 172222222, 'Kelantan', '2025-01-31', 2),
('L004', '$2y$10$G4jUy/SyRv81/OArrKjYQul1wAoUABNQqLV1I95PDuppDjEDuD5MW', 'basir.hadi@gmail.com', 'Basir Hadi', 183333333, 'W.P. Kuala Lumpur', '2025-01-31', 2),
('S001', '$2y$10$6JM.e8sPC4qYRseSlMdk.egZYIOI/N6B7koSQI5EsvKGpwK1J1UrO', 'farhah.talia@gmail.com', 'Farhah Talia', 198765432, 'Perlis', '2025-01-31', 1),
('S002', '$2y$10$4xGVutqqvBzpmUK//2Dh/OWTkP9FLjcPN7jqKwerSrvkWcYntu6Fa', 'hakim.sari@gmail.com', 'Hakim Sari', 187653892, 'Putrajaya', '2025-01-31', 1),
('S003', '$2y$10$n.4DlcepB.FFG0BXPr6Voeca.RNv0pVU6C8XrZWtq4X8dirDTLZaC', 'maria.chew@gmail.com', 'Maria Chew', 346921657, 'Terengganu', '2025-01-31', 1),
('S004', '$2y$10$gsfOG6qZruI.OMcdQG4UyO8MPu7yMf4QXyHUSRKgKNeAkiPMYUGAq', 'thamvil.peghi@gmail.com', 'Thamvil Peghi', 471849723, 'Penang', '2025-01-31', 1),
('S005', '$2y$10$MaVYvQRbY/h41XEKWff.jOjMJZgtAMXkR/Yb/HiXTYAdom8MxuEwW', 'arjuna.nirmala@gmail.com', 'Arjuna Nirmala', 123456789, 'Pahang', '2025-01-31', 1),
('S006', '$2y$10$qyMnrEAe6Kt.XcKxW55hfuqf1d9sxU4FaFOk5u7InGOG/hvwIB7e6', 'kasih.cendana@gmail.com', 'Kasih Cendana', 192222222, 'Johor', '2025-01-31', 1),
('S007', '$2y$10$Ah2OQhmoOB667fdeMBSE9uaLfkTPXhBIvsA/AwNQDiIG5kWuyUxgi', 'yung.kai@gmail.com', 'Lan Yung Kai', 619728345, 'Negeri Sembilan', '2025-01-31', 1);

-- --------------------------------------------------------

--
-- Table structure for table `u_utype`
--

CREATE TABLE `u_utype` (
  `t_id` int(11) NOT NULL,
  `t_desc` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `u_utype`
--

INSERT INTO `u_utype` (`t_id`, `t_desc`) VALUES
(1, 'Student'),
(2, 'Lecturer'),
(3, 'Admin');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `tb_course`
--
ALTER TABLE `tb_course`
  ADD PRIMARY KEY (`c_code`),
  ADD KEY `c_lec` (`c_lec`);

--
-- Indexes for table `tb_registration`
--
ALTER TABLE `tb_registration`
  ADD PRIMARY KEY (`r_tid`),
  ADD KEY `r_status` (`r_status`),
  ADD KEY `r_student` (`r_student`),
  ADD KEY `r_course` (`r_course`);

--
-- Indexes for table `tb_status`
--
ALTER TABLE `tb_status`
  ADD PRIMARY KEY (`s_id`);

--
-- Indexes for table `tb_user`
--
ALTER TABLE `tb_user`
  ADD PRIMARY KEY (`u_sno`),
  ADD UNIQUE KEY `u_email` (`u_email`),
  ADD KEY `u_utype` (`u_utype`);

--
-- Indexes for table `u_utype`
--
ALTER TABLE `u_utype`
  ADD PRIMARY KEY (`t_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `tb_registration`
--
ALTER TABLE `tb_registration`
  MODIFY `r_tid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=37;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `tb_course`
--
ALTER TABLE `tb_course`
  ADD CONSTRAINT `tb_course_ibfk_1` FOREIGN KEY (`c_lec`) REFERENCES `tb_user` (`u_sno`);

--
-- Constraints for table `tb_registration`
--
ALTER TABLE `tb_registration`
  ADD CONSTRAINT `tb_registration_ibfk_1` FOREIGN KEY (`r_status`) REFERENCES `tb_status` (`s_id`),
  ADD CONSTRAINT `tb_registration_ibfk_2` FOREIGN KEY (`r_student`) REFERENCES `tb_user` (`u_sno`),
  ADD CONSTRAINT `tb_registration_ibfk_3` FOREIGN KEY (`r_course`) REFERENCES `tb_course` (`c_code`);

--
-- Constraints for table `tb_user`
--
ALTER TABLE `tb_user`
  ADD CONSTRAINT `tb_user_ibfk_1` FOREIGN KEY (`u_utype`) REFERENCES `u_utype` (`t_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
